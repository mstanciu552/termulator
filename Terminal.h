#include "rendering/Screen.h"
#include "terminal/Command.h"

class Terminal {
    private:
        Screen* screen;
        Command* command;
    public:
        Terminal();
        ~Terminal();

        void init();
};