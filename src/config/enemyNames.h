#pragma once

#include <string_view>
#include <array>

namespace EnemyNames {

    using namespace std::string_view_literals;

    constexpr std::array enemyNames {  
        "Goblin"sv,
        "Slime"sv,
        "Orc"sv,
        "Troll"sv,
        "Vampire"sv,
        "Werewolf"sv,
        "Zombie"sv,
        "Skeleton"sv,
        "Ghost"sv,
        "Demon"sv,
        "Spider"sv,
        "Bandit"sv,
        "Witch"sv,
        "Mummy"sv,
        "Rat"sv,
        "Imp"sv
    };

    constexpr std::array bigEnemyNames {  
        "Dragon"sv,
        "Minotaur"sv,
        "Hydra"sv,
        "Phoenix"sv,
        "Lich"sv,
        "Giant"sv,
        "Chimera"sv
    };

    std::string_view getRandomEnemyName(bool isBigEnemy = false) {
        if (isBigEnemy) {
            return bigEnemyNames[Random::get(0, bigEnemyNames.size() - 1)];
        } else {
            return enemyNames[Random::get(0, enemyNames.size() - 1)];
        }
    }

};