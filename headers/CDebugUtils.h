// https://en.cppreference.com/w/cpp/preprocessor/replace

#pragma once
#include <iostream>

// comment out the following line to disable debug mode
// debug mode will print out extra information to the console for debugging purposes
// #define DEBUG_MODE

#ifdef DEBUG_MODE
#define DEBUG_PRINT(msg) \
    std::cout << "Debug (" << __FILE__ << ":" << __LINE__ << "): " << msg << std::endl
#else
#define DEBUG_PRINT(msg)
#endif
