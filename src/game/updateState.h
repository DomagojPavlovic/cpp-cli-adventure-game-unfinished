#pragma once

#include "player.h"
#include "enemy.h"
#include <vector>

struct UpdateState {

    Player* player { nullptr };
    std::vector<Enemy>* enemies { nullptr };

    // general game stats
    int floor {};
    int room {};
};