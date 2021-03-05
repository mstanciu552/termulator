#include "Command.h"

Command::Command() {}
Command::~Command() {}

void Command::run(std::string command) {
    system(command.c_str());

}