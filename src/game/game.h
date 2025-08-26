#pragma once

#include "randomUtils.h"
#include "player.h"
#include "enemy.h"
#include "location.h"
#include <vector>

class Game {

public:

    Game() :  
        m_player {},
        m_enemies {},
        m_location {} 
    {}

    Player* getPointerToPlayer() { return &m_player; }

    std::vector<Enemy>* getPointerToEnemies() { return &m_enemies; }

    Location* getPointerToLocation() { return &m_location; }

    void addEnemy(int level, bool isBigEnemy = false) {
        m_enemies.push_back(RandomUtils::generateRandomEnemy(level, isBigEnemy));
    }

    void removeAllEnemies() {
        m_enemies.clear();
    }

private:

    Player              m_player {};
    std::vector<Enemy>  m_enemies {};
    Location            m_location {};

};