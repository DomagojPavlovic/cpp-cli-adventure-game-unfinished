#include "randomUtils.h"

#include "random.h"
#include "enemyNames.h"
#include "enemyValues.h"

Enemy RandomUtils::generateRandomEnemy(int level, bool isBigEnemy = false) {
    if (level < 1 || level > EnemyValues::maxEnemyLevel) {
        throw std::runtime_error("Invalid enemy level.");
    }

    return { 
        level, 
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::hp, level), 
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::armor, level), 
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::resistance, level),  
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::blockChance, level), 
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::strength, level),
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::intelligence, level),
        EnemyValues::getRandomEnemyValueForLevel(EnemyValues::gold, level),
        EnemyNames::getRandomEnemyName(isBigEnemy)
    };
}

bool RandomUtils::executePercetageChance(int percentage) {
    if (percentage < 0 || percentage > 100) {
        throw std::runtime_error("Percentage must be between 0 and 100.");
    }
    return Random::get(1, 100) <= percentage;
}

