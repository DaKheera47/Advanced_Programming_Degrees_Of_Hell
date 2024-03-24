#pragma once

#include "../CSpace.h"
#include "../enums/ESpaceType.h"

class FSpace
{
public:
    FSpace() = default;

    /**
     * @brief Creates a new space object of the specified type.
     * @param incomingSpace The type of space to create, defined by the ESpaceType enum.
     * @return A shared pointer to the created CSpace object.
     */
    std::shared_ptr<CSpace> CreateNewSpace(ESpaceType incomingSpace);
};
