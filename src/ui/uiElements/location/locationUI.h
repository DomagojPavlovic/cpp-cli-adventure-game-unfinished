#pragma once

#include "uiElement.h"
#include "game.h"

class LocationUI : public UIElement {

public:

    LocationUI(Location* location);

    std::map<int, Line> getLines() override;

private:

    Location* m_location {};

};