#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Font.h"

class Screen {
    public:
        Screen();
        ~Screen();

        void init(const char* title, int x, int y, int width, int height, bool fullscreen);

        void handle_events();
        void update();
        void render();

        void clean();
    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        Cursor* cursor;
        Font* font;
        std::string text_input;
};