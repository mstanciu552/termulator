#include "Font.h"

Font::Font(SDL_Renderer* renderer, char* message): renderer(renderer), message(message) {}
Font::~Font() {}

void Font::init(const char* font_path) {
    font = TTF_OpenFont(font_path, 400);
  	SDL_Color WHITE = {255, 255, 255, 255};
    
    render(message, WHITE);

    clean();
}

void Font::render(char* message, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, message, color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}

void Font::clean() {
    TTF_CloseFont(font);
	TTF_Quit();
}