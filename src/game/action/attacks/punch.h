#pragma once

#include "attack.h"
#include "randomUtils.h"

class Punch : public Attack {

public:

    Punch() : 
        m_name { "Punch" }, 
        m_accuracy { 95 },
        m_damagePercentage { 0 }, // Damage is based on player's strength, not weapon
        m_healthCost { 0 },
        m_manaCost { 0 },
        m_staminaCost { 0 },
        m_description { "A free attack that deals damage based on your level, instead of your weapon." } 
    {}
        
    // 2-4 dmg per level
    void execute(Player& player, std::vector<Enemy>& enemies, int index = 0) override {
        enemies[index].takePhysicalDamage(Random::get(2, 4) * player.getLevel());
    }

}