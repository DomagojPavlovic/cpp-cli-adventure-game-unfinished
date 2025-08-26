#pragma once

#include <array>
#include <stdexcept>
	

namespace PlayerLevelConfig {

    constexpr int maxAvailableLevel { 10 };

    enum TableType {
        hp,
        xp, 
        mana,
        stamina,
        strength,
        intelligence,
        maxTableType
    };

    // start with level 2 values
    constexpr int values[][maxAvailableLevel - 1] {
        {3, 4, 5, 6, 7, 8, 9, 10, 15},
        {5, 30, 45, 60, 80, 100, 150, 200, 300},
        {0, 1, 0, 1, 1, 2, 1, 2, 1},
        {1, 0, 1, 0, 2, 1, 2, 1, 2},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    static_assert(std::ssize(values) == maxTableType);

    inline int getLevelUpValue(TableType type, int level) {
        if(type >= maxTableType) {
            throw std::runtime_error("Erroneous table type accessed.");
        }
        return values[type][level - 2];
    }

}