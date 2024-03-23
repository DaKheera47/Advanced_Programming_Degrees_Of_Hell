#pragma once

#include <memory>
#include <string>

struct SChance
{
    int spinResult;
    std::string message;
    int value;

    // Constructor that initializes the members with the given arguments
    SChance(int result, const std::string& msg, int val)
        : spinResult(result), message(msg), value(val)
    {
    }
};
