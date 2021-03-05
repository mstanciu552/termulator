#include <SDL2/SDL.h>

class Cursor {
    private:
        SDL_Renderer* renderer;
        int x, y, width, height;
    public:
        Cursor(SDL_Renderer* renderer, int x, int y, int w, int h);
        ~Cursor();

        void draw();

        void update(int posX, int posY);
};