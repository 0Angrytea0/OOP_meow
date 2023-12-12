#include "npc.h"

void NPC::save(std::ostream &os) {
    os << position.x_ << std::endl;
    os << position.y_ << std::endl;
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const {
    std::lock_guard<std::mutex> lck(mtx);
    if (std::pow(position.x_ - other->position.x_, 2) + std::pow(position.y_ - other->position.y_, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

void NPC::subscribe(std::shared_ptr<Observer> observer){
    observers.push_back(observer);
}

void NPC::fight_notify(NPC& defender, bool win){
    for (auto &o : observers)
        o->on_fight(*this, defender, win);
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << npc.position << " ";
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y)
{
    std::lock_guard<std::mutex> lck(mtx);

    if ((position.x_ + shift_x >= 0) && (position.x_ + shift_x <= max_x))
        position.x_ += shift_x;
    if ((position.y_ + shift_y >= 0) && (position.y_ + shift_y <= max_y))
        position.y_ += shift_y;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}

NpcType NPC::get_type()
{
    std::lock_guard<std::mutex> lck(mtx);
    return type;
}

Point<int> NPC::position_(){
    std::lock_guard<std::mutex> lck(mtx);
    return {position.x_, position.y_};
}