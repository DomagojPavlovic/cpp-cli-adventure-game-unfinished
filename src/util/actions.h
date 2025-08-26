#pragma once

#include "action.h"
#include "punch.h"
#include <array>
#include <stdexcept>
#include <memory>

class Actions {

public:

    static constexpr int s_maxActions { 10 };

    static constexpr char s_defaultAttackChar { 'p' };
    static constexpr int s_defaultAttackIndex { 8 };

    static constexpr char s_defaultSpellChar { 'r' };
    static constexpr int s_defaultSpellIndex { 9 };

    Actions() = default;
    Actions(const Actions&) = delete;
    Actions& operator=(const Actions&) = delete;
    Actions(Actions&&) = default;
    Actions& operator=(Actions&&) = default;

    Action* getAction(char c) const {
        if(c == s_defaultAttackChar) {
            return m_actions[s_defaultAttackIndex];
        } else if(c == s_defaultSpellChar) {
            return m_actions[s_defaultSpellIndex];
        }

        int index = c - '0'; // Convert char to int

        if (index < 0 || index >= s_maxActions) {
            throw std::out_of_range("Index out of range");
        }
        return m_actions[index];
    }

    void addDefaultActions(Action* defaultAttack) {
        m_actions[s_defaultAttackIndex] = defaultAttack;
        // m_actions[s_defaultSpellIndex] = std::make_unique<Action>("Default Spell", 0, 0, s_defaultSpellChar);
    }

private:

    std::array<Action*, s_maxActions> m_actions {};
};