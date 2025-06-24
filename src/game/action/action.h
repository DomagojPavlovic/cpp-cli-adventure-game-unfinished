#pragma once

#include "entity.h"

#include <vector>
#include <string>


class Action {

public:

    Action() = default;

    virtual ~Action() = default;
    
    virtual void execute(
        Player& player, 
        std::vector<Enemy>& enemies, 
        int index = 0
    ) = 0;

private:

    std::string m_name {};
    int m_accuracy {};
    int m_damagePercentage {};
    int m_healthCost {};
    int m_manaCost {};
    int m_staminaCost {};
    std::string m_description {};
    
};