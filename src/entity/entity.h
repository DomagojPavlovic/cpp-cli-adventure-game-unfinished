#pragma once

#include <vector>

class Action;

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

    int getLevel() const { return m_level; }

    int getMaxHealth() const { return m_maxHealth; }

    int getCurrentHealth() const { return m_currentHealth; }

    int getArmor() const { return m_armor; }

    int getResistance() const { return m_resistance; }

    int getBlockChance() const { return m_blockChance; }

    int getStrength() const { return m_strength; }

    int getIntelligence() const { return m_intelligence; }

    int getGold() const { return m_gold; }

    const std::vector<Action>& getActions() const { return m_actions; }
    
    bool isDead() const { return m_currentHealth <= 0; }

    void takePhysicalDamage(int damage);

    void takeMagicDamage(int damage);


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

    std::vector<Action> m_actions {};
};