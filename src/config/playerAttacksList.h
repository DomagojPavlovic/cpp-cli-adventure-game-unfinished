#pragma once

#include "genericGameConfig.h"
#include "punch.h"
#include "attack.h"

#include <vector>
#include <memory>

namespace PlayerAttacksList {

    inline std::unique_ptr<Attack> defaultAttack { std::make_unique<Punch>() };

    inline std::vector<std::unique_ptr<Attack>> attacks[GameConfig::s_maxFloor] {

        { }, // Floor 1
        { }, // Floor 2
        { }, // Floor 3
        { }, // Floor 4
        { }  // Floor 5
    };


} // namespace PlayerAttacksList