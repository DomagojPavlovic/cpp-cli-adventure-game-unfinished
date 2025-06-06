#pragma once

class Entity {

public:

    Entity(int level, int maxHealth, int armor, 
        int resistance, int blockChance, int strength, 
        int intelligence, int gold) 
        : m_level { level }, m_maxHealth { maxHealth }, m_currentHealth { maxHealth }
        , m_armor { armor }, m_resistance { resistance }
        , m_blockChance { blockChance }, m_strength { strength }
        , m_intelligence { intelligence }, m_gold { gold }
    {}

    Entity() = default;

    int getLevel() { return m_level; }

    int getMaxHealth() { return m_maxHealth; }

    int getCurrentHealth() { return m_currentHealth; }

    int getArmor() { return m_armor; }

    int getResistance() { return m_resistance; }

    int getBlockChance() { return m_blockChance; }

    int getStrength() { return m_strength; }

    int getIntelligence() { return m_intelligence; }

    int getGold() { return m_gold; }

protected:

    int m_level {};

    int m_maxHealth {};
    int m_currentHealth {};
    int m_armor {};
    int m_resistance {};
    int m_blockChance {};

    int m_strength {};
    int m_intelligence {};

    int m_gold {};
};