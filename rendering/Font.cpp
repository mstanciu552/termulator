#include "Font.h"

Font::Font(SDL_Renderer* renderer, int width, int height, Cursor* cursor): renderer(renderer), width(width), height(height), cursor(cursor) {}
Font::~Font() {
    clean();
}

void Font::init(const char* font_path, const char* message) {
    font = TTF_OpenFont(font_path, 30);
    
    render(message);
}

void Font::render(const char* message) {
  	SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, message, color);
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
   	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    cursor->update(getWidth(message), 5);
    render(message);
    SDL_RenderPresent(renderer);
}

void Font::clean() {
    TTF_CloseFont(font);
	TTF_Quit();
}

TTF_Font* Font::getFont() {
    return font;
}

int Font::getWidth(const char* message) {
    if (!message) return 0;
    int message_width;
    TTF_SizeText(font, message, &message_width, nullptr);
    return message_width;
}

int Font::getHeight(const char* message) {
    if (!message) return 0;
    int message_height;
    TTF_SizeText(font, message, nullptr, &message_height);
    return message_height;
}