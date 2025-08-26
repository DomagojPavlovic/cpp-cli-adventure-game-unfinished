#pragma once

#include "random.h"

namespace EnemyValues {

    constexpr int maxEnemyLevel { 10 };

    enum Type {
        hp,
        armor,
        resistance,
        blockChance,
        strength,
        intelligence,
        gold,
        maxType
    };

    constexpr int values[][maxEnemyLevel] {
        { 5,  7,  25, 40, 50, 71,  95,  126, 150 }, // minHp
        { 10, 28, 42, 60, 80, 100, 130, 160, 200 }, // maxHp

        { 0, 0, 3,  5,  6,  8,  10, 12, 15  }, // minArmor
        { 3, 7, 10, 12, 13, 14, 15, 16, 18 }, // maxArmor

        { 0, 5,  10, 10, 10, 10, 20, 20, 30 }, // minResistance
        { 5, 10, 15, 20, 25, 30, 35, 40, 50 }, // maxResistance

        { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // minBlockChance
        { 2, 4, 6, 7, 8, 9, 10, 11, 12 }, // maxBlockChance

        { 1, 2, 3, 4, 5,  6,  7,  8,  9 }, // minStrength
        { 2, 4, 6, 8, 10, 12, 14, 16, 18 }, // maxStrength

        { 1, 2, 3, 4, 5,  6,  7,  8,  9 }, // minIntelligence
        { 2, 4, 6, 8, 10, 12, 14, 16, 18 }, // maxIntelligence

        { 1,  2,  3,  4,  5,  6,  7,  8,  9 }, // minGold
        { 11, 22, 33, 44, 55, 66, 77, 89, 99 } // maxGold
    };

    static_assert(std::ssize(values) == maxType * 2);

    inline int getRandomEnemyValueForLevel(Type type, int level, bool isBigEnemy = false) {
        if (type >= maxType || level < 1 || level > maxEnemyLevel) {
            throw std::runtime_error("Erroneous enemy value accessed.");
        }
        return Random::get(values[type * 2][level - 1], values[type * 2 + 1][level - 1]) * (isBigEnemy ? 2 : 1);
    }
}