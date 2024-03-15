#include <memory>
#include <iostream>
#include "CGame.h"

// // Getters implementation
// std::vector<std::unique_ptr<CPlayer>> CGame::getPlayers()
// {
//     return players;
// }

// std::vector<CSpace *> CGame::getSpaces()
// {
//     return spaces;
// }

// // Adding players
// void CGame::addPlayer(std::unique_ptr<CPlayer> player)
// {
//     players.push_back(std::move(player));
// }

// // Adding spaces
// void CGame::addSpace(CSpace *space)
// {
//     spaces.push_back(space);
// }

// void CGame::addSpace(const std::vector<CSpace *> &newSpaces)
// {
//     spaces.insert(spaces.end(), newSpaces.begin(), newSpaces.end());
// }

// // Start game
// void CGame::start()
// {
//     // Initialize or reset the game

//     // Print number of players and spaces
//     std::cout << "Number of players: " << players.size() << std::endl;
//     std::cout << "Number of spaces: " << spaces.size() << std::endl;

//     // Print details of each player
//     for (const auto &player : players)
//     {
//         std::cout << "Player name: " << player->getName() << std::endl;
//     }

//     // Print details of each space
//     for (const auto &space : spaces)
//     {
//         std::cout << "Space name: " << space->getName() << std::endl;
//     }
// }

// CGame::CGame(const std::vector<std::unique_ptr<CPlayer>> &newPlayers, const std::vector<CSpace *> &newSpaces)
// {
//     // Optionally clear current players and spaces
//     players = newPlayers;
//     spaces = newSpaces;
//     // Initialize or reset the game
// }
