#include <SDL2/SDL.h>
#include "Cursor.h"

Cursor::Cursor(SDL_Renderer* renderer, int x, int y, int w, int h): renderer(renderer), x(x), y(y), width(w), height(h) {}
Cursor::~Cursor() {}

void Cursor::draw() {
    SDL_Rect cursor = { x, y, width, height };
    SDL_Color color = { 255, 255, 255, 255 };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &cursor);
}

void Cursor::update(int posX, int posY) {
    x = posX;
    y = posY;
   	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    draw();
}