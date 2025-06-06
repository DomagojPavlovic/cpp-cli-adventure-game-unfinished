#pragma once

#include "uiElement.h"

class ResourcesUI : public UIElement {
 
public:

    ResourcesUI(Player* player);

    std::map<int, Line> getLines() override;

private:

    Player* m_player {};

};