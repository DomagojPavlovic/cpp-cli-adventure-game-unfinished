#include "player.h"
#include "playerLevelConfig.h"

Player::Player() : 
        Entity { 
            s_startingLevel, 
            s_startingMaxHp, 
            s_startingArmor, 
            s_startingResistance, 
            s_startingBlockChance, 
            s_startingStrength, 
            s_startingIntelligence, 
            s_startingGold }, 
        m_experience          { s_startingExperience },
        m_experienceToLevelUp { PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::xp, m_level + 1) },
        m_maxMana             { s_startingMaxMana },
        m_currentMana         { s_startingMaxMana },
        m_maxStamina          { s_startingMaxStamina },
        m_currentStamina      { s_startingMaxStamina },
        m_luck                { s_startingMaxLuck },
        m_reflect             { s_startingReflect }
    {

        // m_actions.addDefaultActions(PlayerAttacksList::defaultAttack.get());
    }

bool Player::gainExperience(int experience) {
    m_experience += experience;

    if(m_experience >= m_experienceToLevelUp) {
        levelUp();
        return true;
    }

    return false;
}

void Player::levelUp() {
    m_experience = s_startingExperience;
    ++m_level;
    m_experienceToLevelUp = PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::xp, m_level + 1);

    m_maxHealth += PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::hp, m_level);
    m_maxMana += PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::mana, m_level);
    m_maxStamina += PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::stamina, m_level);
    m_strength += PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::strength, m_level);
    m_intelligence += PlayerLevelConfig::getLevelUpValue(PlayerLevelConfig::intelligence, m_level);

    
}