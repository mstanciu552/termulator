#include <iostream>

class Command {
    private:
    public:
        Command();
        ~Command();

        void run(std::string command);
        std::string execute(std::string command);
};