#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


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
};