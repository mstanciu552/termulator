#include <iostream>
#include <string>
#include "Screen.h"


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
				text_input += event.text.text;
				printf("%s", event.text.text);
				font->update(text_input.c_str());
			} else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_BACKSPACE) {
					text_input.pop_back();
					printf("%s", text_input.c_str());
					font->delete_last(text_input.c_str());
				}
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

	font = new Font(renderer, 10, 10);
	font->init("fonts/terminess.ttf", text_input.c_str());

	SDL_RenderPresent(renderer);
}

// Cleaning Memory
void Screen::clean() {
    SDL_StopTextInput();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}