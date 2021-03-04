#include "Screen.h"

// Color struct
typedef struct Color {
	int r, g, b, a;
	Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a) {}
} Color;

Screen::Screen() {}
Screen::~Screen() {}

void Screen::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
    window = SDL_CreateWindow(title, x, y, width, height, fullscreen);
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
	SDL_RenderPresent(renderer);
}

// Cleaning Memory
void Screen::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}