#include "actionsUI.h"
#include "actions.h"
#include <stdexcept>
#include <iostream>

void ActionsUI::fillStringWithSpaces(std::string& str, int length) {
    if (std::ssize(str) < length) {
        str.append(length - str.size(), ' ');
    }
}

ActionsUI::ActionsUI(Player* player)
    : UIElement {
        UI::s_actionsUiStartingLine,
        UI::s_actionsUiAlignment
    },
    m_player { player } 
    {}

std::string ActionsUI::getActionName(Action* action) const {
    if(action == nullptr) {
        return " - ";
    }
    return action->getName();
}

std::map<int, Line> ActionsUI::getLines() {

    if(m_player == nullptr) throw std::runtime_error("Player pointer is null.");

    std::vector<std::string> lines {};

    lines.push_back(createTitleLine());

    lines.push_back("");

    // default attack and spell

    Action* defaultAttack = m_player->getActions().getAction(Actions::s_defaultAttackChar);
    std::string line { "[" + std::string{ Actions::s_defaultAttackChar } + "] " + getActionName(defaultAttack) };
    fillStringWithSpaces(line, s_namesLineLength);

    line += createCostLabelFromAction(defaultAttack);
    fillStringWithSpaces(line, s_namesLineLength + s_costsLineLength);

    Action* defaultSpell = m_player->getActions().getAction(Actions::s_defaultSpellChar);
    line += "[" + std::string{ Actions::s_defaultSpellChar } + "] " + getActionName(defaultSpell);
    fillStringWithSpaces(line, s_namesLineLength * 2 + s_costsLineLength);

    line += createCostLabelFromAction(defaultSpell);
    fillStringWithSpaces(line, s_namesLineLength * 2 + s_costsLineLength * 2);

    lines.push_back(line);

    // other attacks and spells
    for (size_t i { 0 }; i < Actions::s_maxActions / 2 - 1; ++i) {

        Action* attack = m_player->getActions().getAction(static_cast<char>('0' + i));
        
        std::string line { "[" + std::to_string(i) + "] " + getActionName(attack) };
        fillStringWithSpaces(line, s_namesLineLength);

        
        line += createCostLabelFromAction(attack);
        fillStringWithSpaces(line, s_namesLineLength + s_costsLineLength);

        int spellIndex = static_cast<int>(i + Actions::s_maxActions / 2 - 1);
        
        Action* spell = m_player->getActions().getAction(static_cast<char>('0' + spellIndex));

        line += "[" + std::to_string(spellIndex) + "] " + getActionName(spell);
        fillStringWithSpaces(line, s_namesLineLength * 2 + s_costsLineLength);

        line += createCostLabelFromAction(spell);
        fillStringWithSpaces(line, s_namesLineLength * 2 + s_costsLineLength * 2);

        lines.push_back(line);
    }

    
    int maxLineLength { 0 };
    
    for(const auto& line : lines) {
        maxLineLength = std::max(maxLineLength, static_cast<int>(line.size()));
    }
    

    std::map<int, Line> output {};

    for (size_t i { 0 }; i < lines.size(); ++i) {
        output.insert({ m_startingLine + i, { lines[i], maxLineLength, m_alignment } });
    }



    return output;
}

std::string ActionsUI::createTitleLine() {

    std::string line { "Attacks:" };
    fillStringWithSpaces(line, s_namesLineLength);

    line += "Cost:";
    fillStringWithSpaces(line, s_namesLineLength + s_costsLineLength);

    line += "Spells:";
    fillStringWithSpaces(line, s_namesLineLength * 2 + s_costsLineLength);

    line += "Cost:";
    fillStringWithSpaces(line, s_namesLineLength * 2 + s_costsLineLength * 2);

    line += "Checks:";
    fillStringWithSpaces(line, s_namesLineLength * 3 + s_costsLineLength * 2);

    return line;
}

std::string ActionsUI::createCostLabelFromAction(Action* action) {
    if (action == nullptr) {
        return "";
    }

    std::string costLabel {};


    if (action->getHealthCost() > 0) {
        costLabel += "HP:" + std::to_string(action->getHealthCost()) + " ";
    }
    if (action->getManaCost() > 0) {
        costLabel += "MP:" + std::to_string(action->getManaCost()) + " ";
    }
    if (action->getStaminaCost() > 0) {
        costLabel += "SP:" + std::to_string(action->getStaminaCost()) + " ";
    }

    if (costLabel.empty()) {
        costLabel = " - ";
    }

    fillStringWithSpaces(costLabel, s_costsLineLength);
    return costLabel;
}