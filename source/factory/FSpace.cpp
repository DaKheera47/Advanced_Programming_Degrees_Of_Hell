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
#include "CDebugUtils.h"
#include "CUtils.h"

std::shared_ptr<CSpace> FSpace::CreateNewSpace(ESpaceType incomingSpace)
{
    std::shared_ptr<CSpace> newSpace;

    switch (incomingSpace)
    {
        case ESpaceType::ASSESSMENT:
            DEBUG_PRINT("Got an assignment!");
            // create a CAssessment
            newSpace = std::make_shared<CAssessment>(incomingSpace);

            break;

        case ESpaceType::WELCOME_WEEK:
            DEBUG_PRINT("Got a Welcome Week!");
            // create a CWelcomeWeek
            newSpace = std::make_shared<CWelcomeWeek>(incomingSpace);

            break;

        case ESpaceType::EXTRA_CURRICULAR_ACTIVITY:
            DEBUG_PRINT("Got an extracurricular activity!");
            // create a CExtraCurricularActivity
            newSpace = std::make_shared<CExtraCurricularActivity>(incomingSpace);

            break;

        case ESpaceType::BONUS:
            DEBUG_PRINT("Got a bonus!");
            // create a CBonus
            newSpace = std::make_shared<CBonus>(incomingSpace);

            break;

        case ESpaceType::BOGUS:
            DEBUG_PRINT("Got a bogus!");
            // create a CBogus
            newSpace = std::make_shared<CBogus>(incomingSpace);

            break;

        case ESpaceType::PLAGIARISM_HEARING:
            DEBUG_PRINT("Got a plagiarism hearing!");
            // create a CPlagiarismHearing
            newSpace = std::make_shared<CPlagiarismHearing>(incomingSpace);

            break;

        case ESpaceType::ACCUSED_OF_PLAGIARISM:
            DEBUG_PRINT("Got accused of plagiarism!");
            // create a CAccusedOfPlagiarism
            newSpace = std::make_shared<CAccusedOfPlagiarism>(incomingSpace);

            break;

        case ESpaceType::SKIP_CLASSES:
            DEBUG_PRINT("Got to skip classes!");
            // create a CSkipClasses
            newSpace = std::make_shared<CSkipClasses>(incomingSpace);

            break;

        default:
            break;
    }

    return newSpace;
}
