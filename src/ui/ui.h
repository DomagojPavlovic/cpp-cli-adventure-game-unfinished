#pragma once

#include "uiAlignment.h"
#include "uiElement.h"
#include <string_view>
#include <memory>
#include <vector>

class UIElement;

class UI {

public:

	//general config
	constexpr static int s_width 				{ 220 };
	constexpr static int s_height 				{ 70 };
	constexpr static int s_numberOfEmptyLines 	{ s_height + 20 };
	constexpr static int s_margins				{ 1 };

	//specific ui component locations config
	constexpr static int s_resourcesUiStartingLine		{ 2 };
	constexpr static UIAlignment s_resourcesUiAlignment	{ UIAlignment::L };	
	
	constexpr static int s_locationUiStartingLine		{ 1 };
	constexpr static UIAlignment s_locationUiAlignment	{ UIAlignment::M };


	UI();

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