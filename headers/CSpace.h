#pragma once

#include <iostream>
#include <memory>
#include <string>

// #include "CPlayer.h"
#include "./enums/ESpaceType.h"

// Forward declarations to avoid circular dependencies
class CPlayer;
class CBoard;

class CSpace
{
protected:
    ESpaceType mType;
    std::string mName;
    int mMotivationCost;
    int mSuccess;
    int mYear;

public:
    CSpace(){};
    CSpace(ESpaceType type) { mType = type; };

    /**
     * @brief Constructor for CSpace
     *
     * @param name The name of the space
     * @param type The type of the space
     * @param motivationCost The motivational cost of the space
     * @param success The success value of the space
     * @param year The year of study associated with the space
     */
    CSpace(const std::string& name, ESpaceType type, int motivationCost, int success, int year)
    {
        mName = name;
        mType = type;
        mMotivationCost = motivationCost;
        mSuccess = success;
        mYear = year;
    }

    /**
     * @brief Equality operator for CSpace
     *
     * @param other The other CSpace object to compare with
     * @return true if the spaces have the same name and type, false otherwise
     */
    bool operator==(const CSpace& other) const
    {
        return this->mName == other.mName && this->mType == other.mType;
    };

    virtual ~CSpace() {}  // Virtual destructor for safe polymorphic use

    /**
     * @brief Pure virtual function to handle player landing on the space
     *
     * @param pPlayer The player who landed on the space
     * @param pBoard The game board
     */
    virtual void PlayerLanded(std::shared_ptr<CPlayer>& pPlayer,
                              std::unique_ptr<CBoard>& pBoard) = 0;

    /**
     * @brief Get the type of the space
     *
     * @return The type of the space
     */
    virtual ESpaceType GetType() const { return mType; }

    /**
     * @brief Get the name of the space
     *
     * @return The name of the space
     */
    virtual const std::string& GetName() const { return mName; }

    /**
     * @brief Get the motivational cost of the space
     *
     * @return The motivational cost of the space
     */
    virtual int GetMotivationCost() const { return mMotivationCost; }

    /**
     * @brief Get the success value of the space
     *
     * @return The success value of the space
     */
    virtual int GetSuccess() const { return mSuccess; }

    /**
     * @brief Get the year of study associated with the space
     *
     * @return The year of study associated with the space
     */
    virtual int GetYear() const { return mYear; }

    /**
     * @brief Set the type of the space
     *
     * @param type The new type of the space
     */
    virtual void SetType(ESpaceType type) { mType = type; }

    /**
     * @brief Set the name of the space
     *
     * @param name The new name of the space
     */
    virtual void SetName(const std::string& name) { mName = name; }

    /**
     * @brief Set the motivational cost of the space
     *
     * @param motivationCost The new motivational cost of the space
     */
    virtual void SetMotivationCost(int motivationCost) { mMotivationCost = motivationCost; }

    /**
     * @brief Set the success value of the space
     *
     * @param success The new success value of the space
     */
    virtual void SetSuccess(int success) { mSuccess = success; }

    /**
     * @brief Set the year of study associated with the space
     *
     * @param year The new year of study associated with the space
     */
    virtual void SetYear(int year) { mYear = year; }
};

using UniqSpaceVector = std::vector<std::unique_ptr<CSpace>>;
using UniqSpace = std::unique_ptr<CSpace>;
