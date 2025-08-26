#pragma once

#include "entity.h"
#include <string>
#include <string_view>

class Enemy : public Entity {

public: 
    Enemy(int level, int maxHealth, int armor, 
          int resistance, int blockChance, int strength, 
          int intelligence, int gold, std::string_view name) 
        : Entity(level, maxHealth, armor, resistance, blockChance, strength, intelligence, gold)
        , name { name }
    {}

    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;
    Enemy(Enemy&&) = default;
    Enemy& operator=(Enemy&&) = default;


    const std::string& getName() const { return name; }

private:

    std::string name;

};