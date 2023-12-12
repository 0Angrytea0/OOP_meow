#pragma once

#include <iostream>
#include <string>
#include "npc.h"

class Squirrel : public NPC {
    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);
public:
    Squirrel() = default;
    Squirrel(const Point<int>& position_);

    void print() override;
    virtual void print(std::ostream &os) override;
    
    virtual void save(std::ostream &os) override;
    virtual bool accept(NPCVisitor& visitor, NPC& attacker) override;

    virtual int get_dkill() const {
            return S_distance_kill;
        }
    virtual int get_dmove() const {
        return S_distance_move;
    }

private:
    int S_distance_kill = 5;
    int S_distance_move = 5;

};

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);