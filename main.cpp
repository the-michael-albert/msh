#include <iostream>
#include <string>
#include "command.h"
#include <unistd.h>
#include <vector>
#include <cstring>
#include <cerrno>

#include "log.h"

using namespace std;


// Command execution
void executeCommand(command cmd) {
    cmd.execute();
}
// Command parser
command parseCommand(string input) {
    return command(input);
}

int main() {
    string input;
    while (true) {
        log::printBlue("[" + command::getDir() + "] > ");
        log::setGreen();
        getline(cin, input);
        log::reset();

        auto cmd = parseCommand(input);
        // Execute the command
        executeCommand(cmd);
    }
    return 0;
}
