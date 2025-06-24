#include "locationUI.h"
#include <stdexcept>

LocationUI::LocationUI(Location* location) 
    : UIElement { 
        UI::s_locationUiStartingLine, 
        UI::s_locationUiAlignment
    },
    m_location { location }
{}


std::map<int, Line> LocationUI::getLines() {

    if(m_location == nullptr) throw std::runtime_error("Location is null.");

    std::string firstLine { "Floor: " + std::to_string(m_location->floor) };
    std::string secondLine { "Room: " + std::to_string(m_location->room) };

    int maxLineLength { static_cast<int>(std::max(firstLine.size(), secondLine.size())) };

    return {
        { m_startingLine, { firstLine, maxLineLength, m_alignment } },
        { m_startingLine + 1, { secondLine, maxLineLength, m_alignment } }
    };
}