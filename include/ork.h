#pragma once

#include <iostream>
#include <string>
#include "npc.h"

class Ork : public NPC {

    friend std::ostream &operator<<(std::ostream &os, Ork &ork);
public:
    Ork() = default;
    Ork(const Point<int>& position_);

    void print() override;
    virtual void print(std::ostream &os) override;
    
    virtual void save(std::ostream &os) override;
    virtual bool accept(NPCVisitor& visitor, NPC& attacker) override;

    virtual int get_dkill() const{
        return O_distance_kill;
    }
    virtual int get_dmove() const{
        return O_distance_move;
    }

private:
    int O_distance_kill = 10;
    int O_distance_move = 20;
};

std::ostream &operator<<(std::ostream &os, Ork &ork);