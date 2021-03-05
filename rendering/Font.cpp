#include "Font.h"
#include <iostream>

Font::Font(SDL_Renderer* renderer, int width, int height): renderer(renderer), width(width), height(height) {}
Font::~Font() {
    clean();
}

void Font::init(const char* font_path, const char* message) {
    font = TTF_OpenFont(font_path, 30);
    
    render(message);
}

void Font::render(const char* message) {


  	SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, message, color, 400);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    SDL_Rect dstrect = { 0, 0, width, height };

	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	SDL_DestroyTexture(texture);

    SDL_RenderPresent(renderer);
}

void Font::update(const char* message) {
    render(message);
}

void Font::delete_last(const char* message) {
    SDL_RenderClear(renderer);
    render(message);
    SDL_RenderPresent(renderer);
}

void Font::clean() {
    TTF_CloseFont(font);
	TTF_Quit();
}