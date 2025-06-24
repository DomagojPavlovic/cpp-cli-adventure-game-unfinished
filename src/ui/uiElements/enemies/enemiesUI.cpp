#include "enemiesUI.h"
#include <stdexcept>

EnemiesUI::EnemiesUI(std::vector<Enemy>* enemies) 
    : UIElement { 
        UI::s_enemiesUiStartingLine, 
        UI::s_enemiesUiAlignment
    },
    m_enemies { enemies }
{}

std::map<int, Line> EnemiesUI::getLines() {

    if(m_enemies == nullptr) throw std::runtime_error("Enemies vector is null.");

    std::vector<std::string> lines;

    int maxLineLength { 0 };

    for (size_t i { 0 }; i < m_enemies->size(); ++i) {
        const Enemy& enemy = (*m_enemies)[i];

        if (enemy.getCurrentHealth() <= 0) continue;

        std::string indexLine { "[" + std::to_string(i + 1) + "]" };
        maxLineLength = std::max(maxLineLength, static_cast<int>(std::ssize(indexLine)));
        lines.push_back(indexLine);

        std::string lvNameLine { "Lv." + std::to_string(enemy.getLevel()) + " " + enemy.getName() };
        maxLineLength = std::max(maxLineLength, static_cast<int>(std::ssize(lvNameLine)));
        lines.push_back(lvNameLine);

        std::string healthLine { "HP: " + std::to_string(enemy.getCurrentHealth()) + "/" + std::to_string(enemy.getMaxHealth()) };
        maxLineLength = std::max(maxLineLength, static_cast<int>(std::ssize(healthLine)));
        lines.push_back(healthLine);

        lines.push_back("");
    }

    std::map<int, Line> output {};

    for (size_t i { 0 }; i < lines.size(); ++i) {
        output.insert({ m_startingLine + i, { lines[i], maxLineLength, m_alignment } });
    }

    return output;
}