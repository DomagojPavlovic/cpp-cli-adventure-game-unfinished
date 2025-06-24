#pragma once

#include "uiAlignment.h"
#include "uiElement.h"
#include "game.h"
#include <string_view>
#include <memory>
#include <vector>

class UIElement;

class UI {

public:

	//general config
	constexpr static int s_width 				{ 200 };
	constexpr static int s_height 				{ 50 };
	constexpr static int s_numberOfEmptyLines 	{ s_height + 20 };
	constexpr static int s_margins				{ 4 };
	constexpr static int s_widthWithoutMargins	{ s_width - (s_margins * 2) };

	//specific ui component locations config
	constexpr static int s_resourcesUiStartingLine		{ 3 };
	constexpr static UIAlignment s_resourcesUiAlignment	{ UIAlignment::L };	
	
	constexpr static int s_locationUiStartingLine		{ 2 };
	constexpr static UIAlignment s_locationUiAlignment	{ UIAlignment::M };

	constexpr static int s_enemiesUiStartingLine		{ 3 };
	constexpr static UIAlignment s_enemiesUiAlignment	{ UIAlignment::R };

	constexpr static int s_actionsUiStartingLine		{ s_height / 2 };
	constexpr static UIAlignment s_actionsUiAlignment	{ UIAlignment::L };


	UI() = default;

	UI(Game& game);

	void showScreen();

	void configureScreenPrompt();

	void configureWidth() const;

	void configureHeight() const;

	void printEmptyLines();

	char prompt(std::string_view message, std::string_view legalChars);

	int alignmentToPositionOnScreen(UIAlignment alignment, int stringLength);

private:

	std::vector<std::unique_ptr<UIElement>> m_combatScreenElements {};

};