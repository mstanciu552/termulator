#include "Terminal.h"

#include <SDL2/SDL.h>

Terminal::Terminal() {}
Terminal::~Terminal() {}

void Terminal::init() {
	const int WIDTH = 820, HEIGHT = 640;

    screen = new Screen();

    screen->init("Termulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
}

Screen* Terminal::getScreen() {
    return screen;
}