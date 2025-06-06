#pragma once

#include "player.h"
#include "enemy.h"
#include "location.h"
#include <vector>

class Game {

public:

    Game() = default;

private:

    Player              m_player {};
    std::vector<Enemy>  m_enemies {};
    Location            m_location {};
    

};