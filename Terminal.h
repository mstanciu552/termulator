#include "rendering/Screen.h"

class Terminal {
    private:
        Screen* screen;
    public:
        Terminal();
        ~Terminal();

        void init();

        Screen* getScreen();
};