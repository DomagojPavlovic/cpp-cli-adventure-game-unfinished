#pragma once

#include "enemy.h"

namespace RandomUtils {

    Enemy generateRandomEnemy(int level, bool isBigEnemy);

    bool executePercetageChance(int percentage);
}
