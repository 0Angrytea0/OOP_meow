#pragma once

#include <iostream>
#include <string>
#include "npc.h"

class Bear : public NPC {

    friend std::ostream &operator<<(std::ostream &os, Bear &bear);

public:
    Bear() = default;
    Bear(const Point<int>& position_);

    void print() override;
    virtual void print(std::ostream &os) override;
    
    virtual void save(std::ostream &os) override;
    virtual bool accept(NPCVisitor& visitor, NPC& attacker) override;

    virtual int get_dkill() const {
        return B_distance_kill;
    }
    virtual int get_dmove() const {
        return B_distance_move;
    }

private:
    int B_distance_kill = 10;
    int B_distance_move = 5;
};

std::ostream &operator<<(std::ostream &os, Bear &bear);