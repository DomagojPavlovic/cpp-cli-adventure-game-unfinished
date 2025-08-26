#pragma once

#include "uiElement.h"
#include "player.h"
#include <string>

class ActionsUI : public UIElement {

public:

    constexpr static int s_namesLineLength { 30 };
    constexpr static int s_costsLineLength { 20 };

    ActionsUI(Player* player);

    std::map<int, Line> getLines() override;

private:

    Player* m_player {};

    void fillStringWithSpaces(std::string& str, int length);
    
    std::string createTitleLine();

    std::string createCostLabelFromAction(Action* action);

    std::string getActionName(Action* action) const;

};