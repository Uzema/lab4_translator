#include <gtest.h>
//#include "term.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    /*std::string meow;
    std::cout << "print your thing: ";
    std::cin >> meow;
    Translator thing(meow);
    thing.everything();*/

    return RUN_ALL_TESTS();
}
