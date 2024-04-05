//
// Created by Michael Albert on 4/4/24.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;


class command {
public:
    //construct from string
    command(std::string& command);

    vector<string> getTokens() const {
        return tokens;
    }

    int execute();

    static string getDir() {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            return {cwd};
        } else {
            return "Error getting current directory";
        }
    }


private:
    vector<string> tokens;

};



#endif //COMMAND_H
