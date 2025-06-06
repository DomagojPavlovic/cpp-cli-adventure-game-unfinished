#include <iostream>
#include "ui.h"
#include "game.h"

int main() {

	Game game {};

	UI ui {};
	
	ui.configureScreenPrompt();
	

	ui.showScreen();


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