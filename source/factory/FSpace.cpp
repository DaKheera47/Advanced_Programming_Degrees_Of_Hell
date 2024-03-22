#include "../headers/factory/FSpace.h"

#include <iostream>

#include "../headers/spaces/CAccusedOfPlagiarism.h"
#include "../headers/spaces/CAssessment.h"
#include "../headers/spaces/CBogus.h"
#include "../headers/spaces/CBonus.h"
#include "../headers/spaces/CExtraCurricularActivity.h"
#include "../headers/spaces/CPlagiarismHearing.h"
#include "../headers/spaces/CSkipClasses.h"
#include "../headers/spaces/CWelcomeWeek.h"
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
            // create a CAssessment
            newSpace = std::make_shared<CAssessment>(incomingSpace);

            break;

        case ESpaceType::WELCOME_WEEK:
            std::cout << "Got a Welcome Week!" << std::endl;
            // create a CWelcomeWeek
            newSpace = std::make_shared<CWelcomeWeek>(incomingSpace);

            break;

        case ESpaceType::EXTRA_CURRICULAR_ACTIVITY:
            std::cout << "Got an extracurricular activity!" << std::endl;
            // create a CExtraCurricularActivity
            newSpace = std::make_shared<CExtraCurricularActivity>(incomingSpace);

            break;

        case ESpaceType::BONUS:
            std::cout << "Got a bonus!" << std::endl;
            // create a CBonus
            newSpace = std::make_shared<CBonus>(incomingSpace);

            break;

        case ESpaceType::BOGUS:
            std::cout << "Got a bogus!" << std::endl;
            // create a CBogus
            newSpace = std::make_shared<CBogus>(incomingSpace);

            break;

        case ESpaceType::PLAGIARISM_HEARING:
            std::cout << "Got a plagiarism hearing!" << std::endl;
            // create a CPlagiarismHearing
            newSpace = std::make_shared<CPlagiarismHearing>(incomingSpace);

            break;

        case ESpaceType::ACCUSED_OF_PLAGIARISM:
            std::cout << "Got accused of plagiarism!" << std::endl;
            // create a CAccusedOfPlagiarism
            newSpace = std::make_shared<CAccusedOfPlagiarism>(incomingSpace);

            break;

        case ESpaceType::SKIP_CLASSES:
            std::cout << "Got to skip classes!" << std::endl;
            // create a CSkipClasses
            newSpace = std::make_shared<CSkipClasses>(incomingSpace);

            break;

        default:
            break;
    }

    return newSpace;
}
