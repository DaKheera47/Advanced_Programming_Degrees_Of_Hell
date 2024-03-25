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
                // Year only increases if a player has done 3 of the assessments of this year.
                vector<shared_ptr<CAssessment>> thisYearAssignments =
                    pPlayer->GetCompletedAssessments(pPlayer->GetYearOfStudy());

                // Make sure there are at least 3 assessments completed of the same year
                if (thisYearAssignments.size() < Constants::kAssessmentsPerYear)
                {
                    cout << pPlayer->GetName()
                         << " has not completed enough assessments to progress to year "
                         << pPlayer->GetYearOfStudy() + 1 << endl;

                    // Message is for starting the year again
                    cout << pPlayer->GetName() << " attends Welcome Week and starts year "
                         << pPlayer->GetYearOfStudy() << " again!" << endl;
                }
                else
                {
                    // being here means new year starting
                    // Year increases by 1
                    pPlayer->SetYearOfStudy(pPlayer->GetYearOfStudy() + 1);

                    // Message for starting a new year
                    cout << pPlayer->GetName() << " has successfully completed Year "
                         << pPlayer->GetYearOfStudy() - 1 << endl;

                    // Check if the player has crossed year 3
                    if (pPlayer->GetYearOfStudy() > Constants::kMaxYears)
                    {
                        cout << "Congratulations to " << pPlayer->GetName()
                             << " on their Graduation Day!" << endl;

                        // End the game
                        return;
                    }

                    // Message for starting the year only if the player has not graduated
                    cout << pPlayer->GetName() << " attends Welcome Week and starts year "
                         << pPlayer->GetYearOfStudy() << "!" << endl;
                }
            }

            // print a message like Vyvyan lands on Ridiculously difficult Programming Task
            cout << pPlayer->GetName() << " lands on " << pPlayer->GetCurrentSpace()->GetName()
                 << endl;

            // Get the player's current space to calculate the effect
            pPlayer->GetCurrentSpace()->PlayerLanded(pPlayer, mpBoard);

            cout << *pPlayer;
        }
    }
}

void CGame::End()
{
    // Print out the final scores of the players
    cout << "Game Over" << endl;
    cout << "============" << endl;

    // Find the player with the highest success
    shared_ptr<CPlayer> pWinner = mPlayers[0];

    for (const auto& pPlayer : mPlayers)
    {
        if (pPlayer->GetSuccess() > pWinner->GetSuccess())
        {
            pWinner = pPlayer;
        }
    }

    cout << pWinner->GetName() << " wins!" << endl;
}
