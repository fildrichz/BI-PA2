// semestralka02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "program.hpp"

int main()
{
    program prog;

    try {
        if (prog.run())
            std::cout << "ran sucessfully" << std::endl;
        else
            std::cout << "error occured while running" << std::endl;
    }
    catch (int errNum) {
        std::cout << "no input" << std::endl;
    }

    std::cout << "ending now" << std::endl;
}

