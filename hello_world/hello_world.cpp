#include <cstdlib>
#include <iostream>
#include <string>
#include <hello_world.h>

std::string say_hello() { return std::string("Hello, CMake world!"); }

int main() {
    std::cout << " Version " << hello_world_VERSION_MAJOR << "."
              << hello_world_VERSION_MINOR << std::endl;
    std::cout << say_hello() << std::endl;
    return EXIT_SUCCESS;
}
