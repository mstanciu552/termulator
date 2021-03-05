#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
    private:
        SDL_Renderer* renderer;
        TTF_Font* font = nullptr;
        char* message;
    public:
        Font(SDL_Renderer* renderer, char* message);
        ~Font();

        void init(const char* font_path);

        void render(char* message, SDL_Color color);

        void clean();
};