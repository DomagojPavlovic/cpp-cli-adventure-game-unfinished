#pragma once

#include "game.h"
#include "random.h"
#include <map>

namespace EnemyCountPerFloorConfig {

    //eg. floor 1 has: [80 perent for 1 enemy], [20 percent for 2 enemies]
    class FloorAndPercentages {

    public:

        FloorAndPercentages(std::map<int, int> percentageAndEnemyCount)
            : percentageAndEnemyCount { percentageAndEnemyCount } {
            
            int percentageSum { 0 };
            for(const auto& [percentage, enemyCount] : percentageAndEnemyCount) {
                if (enemyCount <= 0 || percentage < 0 || percentage > 100) {
                    throw std::invalid_argument("Invalid enemy count or percentage.");
                }
                percentageSum += percentage;
            }
            if (percentageSum != 100) {
                throw std::invalid_argument("Total percentage must equal 100.");
            }

        }
    
    private:

        std::map<int, int> percentageAndEnemyCount {};

    }

    constexpr static std::array<FloorAndPercentages, Game::s_maxFloor> s_enemyCountPerFloorConfig {
        FloorAndPercentages({{ 80, 1 }, { 20, 2 }}),
        FloorAndPercentages({{ 70, 1 }, { 20, 2 }, { 10, 3 }}),
        FloorAndPercentages({{ 60, 1 }, { 22, 2 }, { 18, 3 }}),
        FloorAndPercentages({{ 50, 1 }, { 25, 2 }, { 25, 3 }}),
        FloorAndPercentages({{ 40, 1 }, { 30, 2 }, { 29, 3 }, { 1, 4 }})
    };

    inline int rollEnemyCountForFloor(int floor) {
        if (floor < 1 || floor > Game::s_maxFloor) {
            throw std::out_of_range("Floor number is out of range.");
        }

        const FloorAndPercentages& config = s_enemyCountPerFloorConfig[floor - 1];
        int randomValue = Random::get(1, 100);
        
        for (const auto& [percentage, enemyCount] : config.percentageAndEnemyCount) {
            if (randomValue <= percentage) {
                return enemyCount;
            }
            randomValue -= percentage;
        }
        
        return 1; // Fallback, should not happen if config is correct
    }
    

}