#include "actionsUI.h"
#include <stdexcept>

ActionsUI::ActionsUI(Player* player)
    : UIElement {
        UI::s_actionsUiStartingLine,
        UI::s_actionsUiAlignment
    },
    m_player { player } 
    {}

    // unfinished
std::map<int, Line> ActionsUI::getLines() {

    // if(m_player == nullptr) throw std::runtime_error("Player pointer is null.");

    // std::vector<std::string> lines {};

    // int maxLineLength { 0 };

    // for (size_t i { 0 }; i < m_player->getActions().size(); ++i) {
    //     const Action& action = m_player->getActions()[i];

    //     std::string indexLine { "[" + std::to_string(i + 1) + "]" };
    //     maxLineLength { std::max(maxLineLength, static_cast<int>(std::ssize(indexLine))) };
    //     lines.push_back(indexLine);

    //     std::string nameLine { action.getName() };
    //     maxLineLength { std::max(maxLineLength, static_cast<int>(std::ssize(nameLine))) };
    //     lines.push_back(nameLine);

    //     std::string descriptionLine { action.getDescription() };
    //     maxLineLength { std::max(maxLineLength, static_cast<int>(std::ssize(descriptionLine))) };
    //     lines.push_back(descriptionLine);

    //     lines.push_back("");
    // }

    std::map<int, Line> output {};
    return output;
}
    