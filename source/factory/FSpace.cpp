#include "../headers/factory/FSpace.h"

#include <iostream>

#include "../headers/spaces/CAssessment.h"
#include "CUtils.h"

std::shared_ptr<CSpace> FSpace::CreateNewSpace(ESpaceType incomingSpace)
{
    // std::cout << "Creating a new space!" << " of type " << static_cast<unsigned
    // int>(incomingSpace)
    //           << std::endl;

    std::shared_ptr<CSpace> newSpace = std::make_shared<CSpace>();

    switch (incomingSpace)
    {
        case ESpaceType::ASSESSMENT:
            std::cout << "Got an assignment!" << std::endl;
            // create a cassessment
            newSpace = std::make_shared<CSpace>(incomingSpace);

            break;

        default:
            break;
    }

    return newSpace;
}