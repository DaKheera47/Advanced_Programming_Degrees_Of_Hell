#pragma once

#include <string>
#include <vector>

#include "./enums/ESpaceType.h"
#include "CSpace.h"

class CBoard
{
private:
    std::vector<std::shared_ptr<CSpace>> mSpaces;  ///< Stores all spaces on the board.

public:
    /**
     * @brief Constructs a board by loading spaces from a specified file.
     * @param filename The name of the file from which to load the spaces.
     */
    CBoard(const std::string& filename);

    /** @brief Destructs the CBoard object, cleaning up resources as necessary. */
    ~CBoard();

    /**
     * @brief Retrieves all spaces on the board.
     * @return A vector of shared pointers to CSpace, representing all spaces on the board.
     */
    std::vector<std::shared_ptr<CSpace>> GetSpaces() const;

    /**
     * @brief Retrieves all spaces of a specified type on the board.
     * @param type The type of spaces to retrieve, based on the ESpaceType enumeration.
     * @return A vector of shared pointers to CSpace, representing all spaces of the specified type
     * on the board.
     */
    std::vector<std::shared_ptr<CSpace>> GetSpaces(ESpaceType type) const;
};
