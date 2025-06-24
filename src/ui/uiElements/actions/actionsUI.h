#pragma once

#include "uiElement.h"
#include "player.h"

class ActionsUI : public UIElement {

public:

    ActionsUI(Player* player);

    std::map<int, Line> getLines() override;

private:

    Player* m_player {};
};