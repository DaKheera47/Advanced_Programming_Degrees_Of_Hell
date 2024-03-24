#pragma once

#include <memory>
#include <string>

struct SChance
{
    int spinResult;
    std::string message;
    int value;

    /**
     * @brief Initializes a new SChance object with specified spin result, message, and value.
     * @param result The result of the spin associated with this chance.
     * @param msg The message associated with this chance.
     * @param val The value associated with this chance.
     */
    SChance(int result, const std::string& msg, int val)
        : spinResult(result), message(msg), value(val)
    {
    }
};
