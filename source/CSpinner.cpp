#include "CSpinner.h"

int CSpinner::spin()
{
    std::random_device rd;                        // Obtain a random number from hardware
    std::mt19937 gen(rd());                       // Seed the generator
    std::uniform_int_distribution<> distr(1, 10); // Define the range [1, 10]

    return distr(gen); // Generate a random spin value within the range
}
