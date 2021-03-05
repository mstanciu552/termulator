#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Cursor.h"
#include <iostream>

class Font {
    private:
        SDL_Renderer* renderer;
        TTF_Font* font = nullptr;
        int width, height;
        Cursor* cursor;
    public:
        Font(SDL_Renderer* renderer, int width, int height, Cursor* cursor);
        ~Font();

        void init(const char* font_path, const char* message);

        void render(const char* message);
        void update(const char* message);
        void delete_last(const char* message);

        void clean();

        TTF_Font* getFont();
        int getWidth(const char* message);
        int getHeight(const char* message);
        std::string getMessage();
};