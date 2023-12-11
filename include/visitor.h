#pragma once

#include <iostream>
#include "npc.h"
#include "ork.h"
#include "bear.h"
#include "squirrel.h"
#include "observer.h"


class FightVisitor : public NPCVisitor {
public:
    bool visit(Ork& defender, NPC& attacker) override;
    bool visit(Bear& defender, NPC& attacker) override;
    bool visit(Squirrel& defender, NPC& attacker) override;
};