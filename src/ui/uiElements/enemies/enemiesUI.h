#pragma once
#include "uiElement.h"
#include "game.h"

class EnemiesUI : public UIElement {

    
public:

    EnemiesUI(std::vector<Enemy>* enemies);

    std::map<int, Line> getLines() override;

private:

    std::vector<Enemy>* m_enemies {};
    
};