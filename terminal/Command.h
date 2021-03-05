#include <iostream>

class Command {
    private:
    public:
        Command();
        ~Command();

        void run(std::string command);
};