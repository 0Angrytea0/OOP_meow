#pragma once

#include <iostream>
#include <memory>
#include "npc.h"
#include "bear.h"
#include "ork.h"
#include "squirrel.h"
#include "observer.h"

class NPCFactory {
public:
    static std::shared_ptr<NPC> factory(NpcType type, const Point<int>& position);
};