#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Rendering
#include "rendering/Screen.h"

int main(int argv, char** args) {
	const int WIDTH = 820, HEIGHT = 640;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error initializing SDL %s", SDL_GetError());
	
	if (TTF_Init() != 0)
		printf("Error loading the Font: %s", TTF_GetError());

	Screen* screen = new Screen();

	screen->init("Termulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);


	return 0;
}
