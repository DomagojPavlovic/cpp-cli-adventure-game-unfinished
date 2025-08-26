#pragma once

#include "attack.h"
#include "randomUtils.h"


class Punch : public Attack {

public:

    Punch() : Attack { 
        { "Punch" }, 
        { 95 },
        { 0 }, // Damage is based on player's strength, not weapon
        { 0 },
        { 0 },
        { 0 },
        { "A free attack that deals damage based on your level, instead of your weapon." } 
    }
    {}
        
    // 2-4 dmg per level
    void execute(Player& player, std::vector<Enemy>& enemies, int index = 0) override {

        int dmgCalculation { Random::get(2, 4) * player.getLevel() };
        int addStrength { player.getStrength() };

        enemies[index].takePhysicalDamage(dmgCalculation + addStrength);
    }

};