#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
    private:
        SDL_Renderer* renderer;
        TTF_Font* font = nullptr;
        int width, height;
    public:
        Font(SDL_Renderer* renderer, int width, int height);
        ~Font();

        void init(const char* font_path, const char* message);

        void render(const char* message);
        void update(const char* message);

        void clean();
};