#include "ui.h"
#include "resourcesUI.h"
#include "locationUI.h"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <cstring>
#include <map>
#include <stdexcept>


UI::UI() {
	m_combatScreenElements.push_back(std::make_unique<ResourcesUI>());
	m_combatScreenElements.push_back(std::make_unique<LocationUI>());
}

void UI::showScreen() {
	printEmptyLines();

	for(int i { 0 }; i < s_height; ++i) {

		std::string outputLine(s_width, ' ');

		for(const auto& uiElement : m_combatScreenElements) {
			const std::map<int, Line>& uiElementLines { uiElement->getLines() };
			
			if(uiElementLines.contains(i)) {

				
				const Line& uiElementLine { uiElementLines.at(i) };
				outputLine.replace(
					alignmentToPositionOnScreen(uiElementLine.alignment, uiElementLine.uiElementMaxLength), 
					uiElementLine.text.size(), 
					uiElementLine.text);
			}
		}
		std::cout << outputLine;
	}
}

void UI::configureScreenPrompt() {
	printEmptyLines();
	
	configureWidth();
	
	printEmptyLines();

	configureHeight();
}

void UI::configureWidth() const {
	
	std::cout << '<';
	for (int i{ 1 }; i < s_width - 1; ++i) {
		std::cout << '-';
	}
	std::cout << '>';

	std::cout << '<';
	for (int i{ 1 }; i < s_width - 1; ++i) {
		std::cout << '-';
	}
	std::cout << '>';

	std::cout << "\n";
	std::cout << "Please adjust the width of the prompt until you can see the two full arrows, each on its line.\n";
	std::cout << "You can always right click on top of the prompt, click properties, click the font card and change the font size to reduce or increase it to fit the screen better.\n";
	std::cout << "Enter to go next.\n";
	std::string ignore {};
	
	std::getline(std::cin, ignore);
}

void UI::configureHeight() const {
	
	std::cout << "^\n";
	
	for (int i{ 1 }; i < s_height - 3; ++i) {
		std::cout << "|\n";
	}
	
	std::cout << "|  Please adjust the height of the prompt until you can see the full arrow on the screen.\n";
	std::cout << "|  You can always right click on top of the prompt, click properties, click the font card and change the font size to reduce or increase it to fit the screen better.\n";
	std::cout << "v  Enter to go next.\n";

	std::string ignore {};
	std::getline(std::cin, ignore);
}


void UI::printEmptyLines() {
	for(int i { 0 }; i < s_numberOfEmptyLines; ++i) {
		std::cout << '\n';
	}
}

char UI::prompt(std::string_view message, std::string_view legalChars) {

	char playerInput {};

	while(true) {

		std::cout << message << '\n';
		std::cout << "> ";
		std::cin >> playerInput;
		playerInput = std::tolower(playerInput);

		// check if trash input
		if(!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		
		//check for longer than one char input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1) {
            continue; 
        }

		if(legalChars.find(playerInput) != std::string::npos) {
			return playerInput;
		}
	}
}

int UI::alignmentToPositionOnScreen(UIAlignment alignment, int stringLength) {
	using enum UIAlignment;
	switch(alignment) {
	case L: return s_margins;
	case M: return s_width/2 - stringLength/2;
	case R: return s_width - s_margins - stringLength;
	default: throw std::runtime_error("Undefined UI alignment: " + static_cast<int>(alignment));
	}
}