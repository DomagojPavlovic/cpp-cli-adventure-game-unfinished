#include "entity.h"

// forward declaration
namespace RandomUtils{
    bool executePercetageChance(int percentage);
}
//end forward declaration

void Entity::takePhysicalDamage(int damage) {
    if (isDead()) return;

    if (m_blockChance > 0 && RandomUtils::executePercetageChance(m_blockChance)) {
        return;
    }

    int effectiveDamage = damage - m_armor;
    if (effectiveDamage < 1) effectiveDamage = 1;

    m_currentHealth -= effectiveDamage;
    if (m_currentHealth < 0) m_currentHealth = 0;
}

void Entity::takeMagicDamage(int damage) {
    if (isDead()) return;

    int effectiveDamage = damage * (m_resistance / 100);
    if (effectiveDamage < 1) effectiveDamage = 1;

    m_currentHealth -= effectiveDamage;
    if (m_currentHealth < 0) m_currentHealth = 0;
}