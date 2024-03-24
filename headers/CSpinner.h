#pragma once

#include <random>

class CSpinner
{
private:
    static int spinIdx;

public:
    /**
     * @brief Simulates a spin action, generating and returning a random integer.
     * @return An integer result of the spin, determined randomly.
     */
    static int Spin();
};
