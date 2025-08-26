#include <iostream>
#include "ui.h"
#include "game.h"

int main() {
	Game game {};

	UI ui { game };
	
	ui.configureScreenPrompt();

	ui.showScreen();


    // one encounter
	while(true) {
        //combat

        //show combat screen

        //player selects attack

        //execute action and enemy action

        //refresh screen, showing actions at bottom

        //if win, go next
    }


	return 0;
}

