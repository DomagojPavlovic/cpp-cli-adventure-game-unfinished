#pragma once

#include "action.h"
#include "entity.h"

class Attack : public Action {

public:

    Attack(std::string_view name, int accuracy, int damagePercentage, int healthCost, int manaCost, int staminaCost, std::string_view description)
        : Action(name, accuracy, damagePercentage, healthCost, manaCost, staminaCost, description) {}

    virtual ~Attack() = default;

    virtual void execute(
        Player& player, 
        std::vector<Enemy>& enemies, 
        int index = 0
    ) = 0;
};