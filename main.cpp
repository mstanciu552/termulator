#include <SDL2/SDL.h>
#include <iostream>

typedef struct Color {
	int r, g, b, a;
	Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a) {}
} Color;

void loop();

int main(int argv, char** args) {

	const int WIDTH = 820, HEIGHT = 640;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("Error initializing SDL %s", SDL_GetError());
	
	SDL_Window* window = SDL_CreateWindow("Termulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	// Make the screen black 
	Color* BLACK = new Color(30, 30, 30, 255);
	SDL_SetRenderDrawColor(renderer, BLACK->r, BLACK->g, BLACK->b, BLACK->a);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	// Loop for events
	loop();
	
	// Cleaning Memory
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void loop() {
	bool isRunning = true;
	SDL_Event event;

	while(isRunning) {
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
				break;
			}
		}
	}
}