#pragma once

#include "entity.h"

class Player : public Entity {

public:

    static constexpr int s_startingLevel        { 1 };
    static constexpr int s_startingMaxHp        { 20 };
    static constexpr int s_startingArmor        { 0 };
    static constexpr int s_startingResistance   { 0 };
    static constexpr int s_startingBlockChance  { 0 };
    static constexpr int s_startingStrength     { 1 };
    static constexpr int s_startingIntelligence { 1 };
    static constexpr int s_startingGold         { 0 };
    static constexpr int s_startingExperience   { 0 };
    static constexpr int s_startingMaxMana      { 10 };
    static constexpr int s_startingMaxStamina   { 10 };
    static constexpr int s_startingMaxLuck      { 0 };
    static constexpr int s_startingReflect      { 0 };

    Player();

    bool gainExperience(int experience);

    void levelUp();

    int getExperience() { return m_experience; }

    int getExperienceToLevelUp() { return m_experienceToLevelUp; }

    int getMaxMana() { return m_maxMana; }

    int getCurrentMana() { return m_currentMana; }

    int getMaxStamina() { return m_maxStamina; }

    int getCurrentStamina() { return m_currentStamina; }

    int getLuck() { return m_luck; }

    int getReflect() { return m_reflect; }

private:

    int m_experience {};

    int m_experienceToLevelUp {};

    int m_maxMana {};
    int m_currentMana {};
    int m_maxStamina {};
    int m_currentStamina {};

    int m_luck {};

    int m_reflect {};

};