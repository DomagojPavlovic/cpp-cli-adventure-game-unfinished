#pragma once

#include "player.h"
#include "enemy.h"
#include "location.h"
#include <vector>

class Game {

public:

    Game() = default;

    Player* getPointerToPlayer() { return &m_player; }

    std::vector<Enemy>* getPointerToEnemies() { return &m_enemies; }

    Location* getPointerToLocation() { return &m_location; }

    void addEnemy(const Enemy& enemy) {
        m_enemies.push_back(enemy);
    }

    void removeAllEnemies() {
        m_enemies.clear();
    }

private:

    Player              m_player {};
    std::vector<Enemy>  m_enemies {};
    Location            m_location {};

};