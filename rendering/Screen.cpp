#include <iostream>
#include "Screen.h"
#include "Font.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Color struct
typedef struct Color {
	int r, g, b, a;
	Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a) {}
} Color;

Screen::Screen() {}
Screen::~Screen() {
	clean();
}

void Screen::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
    window = SDL_CreateWindow(title, x, y, width, height, fullscreen);
    SDL_StartTextInput();
	
	render();
	handle_events();

	clean();
}

void Screen::handle_events() {
    isRunning = true;
	SDL_Event event;

	while(isRunning) {
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
				break;
			} else if (event.type == SDL_TEXTINPUT) {
				// Getting user input here
				printf("%s", event.text.text);
			}
		}
	}
}

void Screen::update() {}

void Screen::render() {
    renderer = SDL_CreateRenderer(window, -1, 0);

    Color* BLACK = new Color(30, 30, 30, 255);

	SDL_SetRenderDrawColor(renderer, BLACK->r, BLACK->g, BLACK->b, BLACK->a);
	SDL_RenderClear(renderer);

	char* string_to_render = "testing";
	Font* font = new Font(renderer, string_to_render);
	font->init("fonts/terminess.ttf");

	SDL_RenderPresent(renderer);
}

// Cleaning Memory
void Screen::clean() {
    SDL_StopTextInput();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}