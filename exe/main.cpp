#include "echo/echo.h"

#include <iostream>

int main(int argc, const char* argv[]) {
    std::cout << echo::Echo("Hello echo!") << std::endl;
    return 0;
}
