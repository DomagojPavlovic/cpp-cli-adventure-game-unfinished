#include "resourcesUI.h"
#include <stdexcept>

ResourcesUI::ResourcesUI(Player* player)
    : UIElement {
        UI::s_resourcesUiStartingLine,
        UI::s_resourcesUiAlignment
    },
    m_player { player } 
    {}

std::map<int, Line> ResourcesUI::getLines() {

    if(m_player == nullptr) throw std::runtime_error("Player is null.");
    
    std::string firstLine { "Health:  " + std::to_string(m_player->getCurrentHealth()) + '/' + std::to_string(m_player->getMaxHealth()) };
    std::string secondLine { "Mana:    " + std::to_string(m_player->getCurrentMana()) + '/' + std::to_string(m_player->getMaxMana()) };
    std::string thirdLine { "Stamina: " + std::to_string(m_player->getCurrentStamina()) + '/' + std::to_string(m_player->getMaxStamina()) };
    
    int maxLineLength { static_cast<int>(std::max(firstLine.size(), std::max(secondLine.size(), thirdLine.size()))) };
    
    return {
        { m_startingLine, { firstLine, maxLineLength, m_alignment } },
        { m_startingLine + 1, { secondLine, maxLineLength, m_alignment } },
        { m_startingLine + 2, { thirdLine, maxLineLength, m_alignment } }
    };
}    