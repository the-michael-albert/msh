//
// Created by Michael Albert on 4/4/24.
//

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_YELLOW   = 33,
        FG_CYAN     = 36,
        FG_MAGENTA  = 35,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

class log {
public:
    //red
    static void printRed(const std::string& message) {
        std::cout << Color::Modifier(Color::FG_RED) << message << Color::Modifier(Color::FG_DEFAULT);
    }

    static void setRed() {
        std::cout << Color::Modifier(Color::FG_RED);
    }

    //green
    static void printGreen(const std::string& message) {
        std::cout << Color::Modifier(Color::FG_GREEN) << message << Color::Modifier(Color::FG_DEFAULT);
    }

    static void setGreen() {
        std::cout << Color::Modifier(Color::FG_GREEN);
    }

    //blue
    static void printBlue(const std::string& message) {
        std::cout << Color::Modifier(Color::FG_BLUE) << message << Color::Modifier(Color::FG_DEFAULT);
    }

    static void setBlue() {
        std::cout << Color::Modifier(Color::FG_BLUE);
    }

    //cyan
    static void printCyan(const std::string& message) {
        std::cout << Color::Modifier(Color::FG_CYAN) << message << Color::Modifier(Color::FG_DEFAULT);
    }

    static void setCyan() {
        std::cout << Color::Modifier(Color::FG_CYAN);
    }

    //magenta
    static void printMagenta(const std::string& message) {
        std::cout << Color::Modifier(Color::FG_MAGENTA) << message << Color::Modifier(Color::FG_DEFAULT);
    }

    static void setMagenta() {
        std::cout << Color::Modifier(Color::FG_MAGENTA);
    }


    static void reset() {
        std::cout << Color::Modifier(Color::FG_DEFAULT);
    }


};

#endif //LOG_H
