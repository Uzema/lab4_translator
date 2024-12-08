#include "term.h"

int main(int argc, char** argv) {
    while (true) {
        std::string infix_string;
        std::cout << "print your expression: ";
        std::getline(std::cin, infix_string);
        Translator tr(infix_string);
        tr.everything();
    }
    return 0;
}
