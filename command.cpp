//
// Created by Michael Albert on 4/4/24.
//



#include "command.h"

#include <iostream>
#include <unistd.h>
#include <unordered_map>

#include "log.h"
#include "vector"
#include "string"
#include "sstream"

command::command(string& command) {
    istringstream iss(command);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
}
int execute_external_command(vector<string> tokens) {
    string paths[] = {"/bin", "/usr/bin", "/usr/local/bin"};
    for (const auto& path : paths) {
        // Construct the full path
        string fullPath = path + "/" + tokens[0];

        if (access(fullPath.c_str(), F_OK | X_OK) == 0) {
            cout << "Found command at: " << fullPath << endl;

            //create new process (fork branch)
            pid_t pid = fork();

            if (pid < 0) {
                cerr << "Error forking process." << endl;
                exit(EXIT_FAILURE);
            }
            if (pid == 0) { // we're in child
                vector<const char*> args; // arguments string
                for (const string& token : tokens) {
                    args.push_back(token.c_str());
                }
                args.push_back(nullptr);

                // Execute the command
                execvp(fullPath.c_str(), const_cast<char* const*>(args.data()));
                // execvp success terminates the child process

                cerr << "Failed to execute command: " << strerror(errno) << endl;
                exit(EXIT_FAILURE); // terminate the child process
            } else {
                // Parent process
                // Wait for the child process to finish
                int status;
                waitpid(pid, &status, 0);
                return 0; //merge back into parent
            }
        }
    }
    cerr << "Command not found." << endl;
}

static int cd(char* path) {
    // cout << "Changing directory to: " << path << endl;
    return chdir(path);
}

static int exit(char* args) {
    log::printRed("EXITING!!!");
    exit(0);
}

unordered_map<string, int (*)(char*)> builtins {
        {"cd", cd},
        {"exit", exit}
};


int command::execute() {
    if (builtins.count(tokens[0]) > 0) {
        return builtins[tokens[0]](const_cast<char*>(tokens[1].c_str()));
    }
    return execute_external_command(tokens);
;
}


