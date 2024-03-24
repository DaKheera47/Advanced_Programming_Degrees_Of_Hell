#include "CGame.h"

#include <iostream>
#include <memory>

#include "CUtils.h"
#include "Constants.h"

using namespace std;

CGame::CGame(CPlayerVector& players, unique_ptr<CBoard>& pBoard)
{
    mPlayers = players;
    mpBoard = std::move(pBoard);

    // Set initial positions for all players to the 0th element on the board, so the first space
    for (const auto& pPlayer : players)
    {
        pPlayer->SetCurrentSpace(mpBoard->GetSpaces()[0]);
    }
}

// Start game
void CGame::Start()
{
    // Intro message
    cout << "Welcome to Scumbag College" << endl;
}

void CGame::Play(const int rounds)
{
    for (int roundNum = 1; roundNum <= rounds; roundNum++)
    {
        cout << endl << "ROUND " << roundNum << endl;
        cout << "=========" << endl;

        for (auto& pPlayer : mPlayers)
        {
            // Spin the spinner
            int spinResult = CSpinner::Spin();

            cout << pPlayer->GetName() << " spins " << spinResult << endl;

            // Move the player
            shared_ptr<CSpace> pCurrentSpace = pPlayer->GetCurrentSpace();
            int currentPosIndex = CUtils::GetSpaceIndex(mpBoard->GetSpaces(), pCurrentSpace);
            int boardSize = mpBoard->GetSpaces().size();
            int newPosIndex = (currentPosIndex + spinResult) % boardSize;

            // Move the player to the new position
            pPlayer->SetCurrentSpace(mpBoard->GetSpaces()[newPosIndex]);

            // Check for rollover
            bool hasPassedWelcomeWeek = newPosIndex <= currentPosIndex;

            // Doing additional things if the player has passed the Welcome Week
            if (hasPassedWelcomeWeek)
            {
                // Motivation goes up by Constants::kWwMotivInc
                pPlayer->SetMotivation(pPlayer->GetMotivation() + Constants::kWwMotivInc);
                // Message: '<Player> attends Welcome Week and starts year <year> more motivated!'
                cout << pPlayer->GetName() << " attends Welcome Week and starts year "
                     << pPlayer->GetYearOfStudy() << " more motivated!" << endl;

                // Year only increases if a player has done 3 of the assessments of this year.
                vector<shared_ptr<CAssessment>> thisYearAssignments =
                    pPlayer->GetCompletedAssessments(pPlayer->GetYearOfStudy());

                // Make sure there are at least 3 assessments completed of the same year
                if (thisYearAssignments.size() < Constants::kAssessmentsPerYear)
                {
                    cout << pPlayer->GetName()
                         << " has not completed enough assessments to progress to the next year."
                         << endl;
                    continue;
                }

                // Year increases by 1
                pPlayer->SetYearOfStudy(pPlayer->GetYearOfStudy() + 1);

                // Check if the player has crossed year 3
                if (pPlayer->GetYearOfStudy() > Constants::kMaxYears)
                {
                    cout << "Congratulations! " << pPlayer->GetName() << " has graduated!" << endl;

                    cout << "Final stats: ";
                    cout << *pPlayer;

                    // End the game
                    return;
                }
            }

            // Get the player's current space to calculate the effect
            pPlayer->GetCurrentSpace()->PlayerLanded(pPlayer, mpBoard);

            cout << *pPlayer;
        }
    }
}