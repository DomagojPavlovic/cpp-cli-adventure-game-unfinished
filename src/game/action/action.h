#pragma once

#include <vector>
#include <string>
#include <string_view>

class Player;
class Enemy;

class Action {

public:

    Action(std::string_view name, int accuracy, int damagePercentage, int healthCost, int manaCost, int staminaCost, std::string_view description)
        : m_name(name), 
          m_accuracy(accuracy), 
          m_damagePercentage(damagePercentage), 
          m_healthCost(healthCost), 
          m_manaCost(manaCost), 
          m_staminaCost(staminaCost), 
          m_description(description) {}


    virtual ~Action() = default;
    
    virtual void execute(
        Player& player, 
        std::vector<Enemy>& enemies, 
        int index = 0
    ) = 0;

    const std::string& getName() const { return m_name; }
    const std::string& getDescription() const { return m_description; }
    int getAccuracy() const { return m_accuracy; }
    int getDamagePercentage() const { return m_damagePercentage; }
    int getHealthCost() const { return m_healthCost; }
    int getManaCost() const { return m_manaCost; }  
    int getStaminaCost() const { return m_staminaCost; }

private:

    std::string m_name {};
    int m_accuracy {};
    int m_damagePercentage {};
    int m_healthCost {};
    int m_manaCost {};
    int m_staminaCost {};
    std::string m_description {};
    
};