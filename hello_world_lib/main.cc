#include <cmath>
#include <iostream>
#include <string>

#include "hello_world_conf.h"

// should we include the hello_world header?
#ifdef USE_HELLO
#  include "hello_world.h"
#endif

int main(int argc, char* argv[])
{
    #ifdef USE_HELLO
       std::cout << say_hello() << std::endl;
    #else
	std::cout << "USE_HELLO OFF!" << std::endl;  
    #endif
    return 0;
}

