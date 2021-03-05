#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Rendering
#include "Terminal.h"

int main(int argv, char** args) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error initializing SDL %s", SDL_GetError());
	
	if (TTF_Init() != 0)
		printf("Error loading the Font: %s", TTF_GetError());

	Terminal* terminal = new Terminal();
	terminal->init();

	return 0;
}
