#pragma once

#include "player.h"
#include "enemy.h"
#include <vector>

class Action {

public:

    virtual void execute(
        Player& player, 
        std::vector<Enemy>& enemies, 
        int index = 0
    ) = 0;
};