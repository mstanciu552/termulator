#include <string>
#include "Screen.h"

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
	command = new Command();
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
				font->update(text_input.c_str());
				cursor->update(font->getWidth(text_input.c_str()) + 15, 5);
			} else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_BACKSPACE) {
					if (text_input.size() > 0) {
						text_input.pop_back();
						font->delete_last(text_input.c_str());
					}
            	} else if (event.key.keysym.sym == SDLK_RETURN) {
					// TODO Separate current directory from text
					command->run(text_input);
					text_input = "";
					font->update(text_input.c_str());
					cursor->update(1, 5);
				}
			}
		}
	}
}

void Screen::update() {}

void Screen::render() {
    renderer = SDL_CreateRenderer(window, -1, 0);
    cursor = new Cursor(renderer, 1, 1, 10, 20);

	
	Color* BLACK = new Color(30, 30, 30, 255);

	SDL_SetRenderDrawColor(renderer, BLACK->r, BLACK->g, BLACK->b, BLACK->a);
	SDL_RenderClear(renderer);

	cursor->draw();

	font = new Font(renderer, 10, 10, cursor);
	font->init("fonts/terminess.ttf", text_input.c_str());
	cursor->update(font->getWidth(text_input.c_str()), 5);
}


// Cleaning Memory
void Screen::clean() {
    SDL_StopTextInput();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}