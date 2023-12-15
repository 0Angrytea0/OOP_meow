
#include "npc.h"
#include "ork.h"
#include "bear.h"
#include "squirrel.h"
//#include "factory.h"
#include "visitor.h"
#include <shared_mutex>

#include <sstream>

#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using set_t = std::set<std::shared_ptr<NPC>>;

using namespace std::chrono_literals;
std::mutex print_mutex;

class TextObserver : public Observer {
private:
    TextObserver(){};
public:
    static std::shared_ptr<Observer> get(){
        static TextObserver instance;
        return std::shared_ptr<Observer>(&instance, [](Observer *) {});
    }
    void on_fight(NPC& attacker, NPC& defender, bool win)
    {
        if (win)
        {
            std::lock_guard<std::mutex> lck(print_mutex);
            std::cout << std::endl
                    << "Murder --------" << std::endl;
            std::cout << "Killer: ";
            attacker.print();
            std::cout << "Victim: ";
            defender.print();
        }
    }
};

class NPCFactory{
public:
    static std::shared_ptr<NPC> factory(NpcType type, const Point<int>& position){
        std::shared_ptr<NPC> result;
        switch(type) {
            case NpcType::BearType:
                result = std::make_shared<Bear>(position);
                break;
            case NpcType::OrkType:
                result = std::make_shared<Ork>(position);
                break;
            case NpcType::SquirrelType:
                result = std::make_shared<Squirrel>(position);
                break;
            default:
                throw std::invalid_argument("Invalid type");
                break;
        }
        if(result){
            result->subscribe(TextObserver::get());
            // result->subscribe(FileObserver::get("log.txt"));
        }
        return result;
    }
};

std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (!is.is_open()){
        std::cerr << "Error: " << std::endl;
    }
    int count, x, y;
    int type;
    is >> count;
    for (int i = 0; i < count; ++i){
        is >> type >> x >> y;
        result.insert(NPCFactory::factory(static_cast<NpcType>(type), Point(x, y)));
    }
        
    is.close();
    
    return result;
}


set_t fight(const set_t& array, size_t distance) {
    set_t dead_list;

    FightVisitor visitor;

    for (const auto& attacker : array) {
        for (const auto& defender : array) {
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {
                bool success{false};
                success = defender->accept(visitor, *attacker);
                if (success) {
                    dead_list.insert(defender);
                }
            }
        }
    }

    return dead_list;
}

struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};

struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager{
    std::queue<FightEvent> events;
    std::shared_mutex mtx;
    FightVisitor visitor;
public:
    FightManager() {}
    static FightManager& get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        while (true)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {
                        if (event->attacker->is_alive())     // no zombie fighting!
                            if (event->defender->is_alive()) // already dead!
                                if (event->defender->accept(visitor, *event->attacker))
                                    event->defender->must_die();
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }
};


int main(){
    set_t npcs;
    const int MAX_X{100};
    const int MAX_Y{100};

    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 50; ++i)
    {
        npcs.insert(NPCFactory::factory(NpcType(std::rand() % 3 ), Point(std::rand() % MAX_X, std::rand() % MAX_Y)));
    }
    std::cout << "Starting list:" << std::endl
              << npcs;
    
    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&npcs, MAX_X, MAX_Y]()
                            {

        while (true)
            {
                // move phase
                for (std::shared_ptr<NPC> npc : npcs)
                {
                        if(npc->is_alive()){
                            int shift_x = std::rand() % 20 - npc->get_dmove();
                            int shift_y = std::rand() % 20 - npc->get_dmove();
                            npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                        }
                }
                // lets fight
                for (std::shared_ptr<NPC> npc : npcs)
                    for (std::shared_ptr<NPC> other : npcs)
                        if (other != npc)
                            if (npc->is_alive())
                            if (other->is_alive())
                            if (npc->is_close(other, npc->get_dkill()))
                                FightManager::get().add_event({npc, other});

                std::this_thread::sleep_for(1s);
            } 
    });

    while (true)
    {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : npcs)
            {
                auto [x, y] = npc->position_();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                    case BearType:
                        fields[i + grid * j] = 'B';
                        break;
                    case SquirrelType:
                        fields[i + grid * j] = 'S';
                        break;
                    case OrkType:
                        fields[i + grid * j] = 'O';
                        break;

                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

    move_thread.join();
    fight_thread.join();

    return 0;

//     std::cout << "Saving ..." << std::endl;
//     save(npcs, "npc.txt");

//     std::cout << "Loading ..." << std::endl;
//     npcs = load("npc.txt");

//     std::cout << "Fighting ..."  << std::endl 
//             << "_________NPCS_________"
//                         << std::endl
//                         << npcs
//             << "______________________" 
//             << std::endl << std::endl;

//     for (size_t distance = 20; (distance <= 200) && !npcs.empty(); distance += 20)
//     {
//         std::cout << "_________NEW ROUND_________"  << std::endl;
//         auto dead_list = fight(npcs, distance);
//         for (auto &d : dead_list)
//             npcs.erase(d);
//         std::cout << "Fight stats ----------" << std::endl
//                   << "distance: " << distance << std::endl
//                   << "killed: " << dead_list.size() << std::endl
//                   << std::endl;

//     }

//     std::cout << "Survivors: " << npcs;

//     return 0;


}