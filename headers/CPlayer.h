#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "./spaces/CAssessment.h"
#include "CSpace.h"

class CAssessment;

class CPlayer
{
private:
    std::string mName;
    int mMotivation = 1000;
    int mSuccess = 0;
    int mYearOfStudy = 1;

    std::shared_ptr<CSpace> mpCurrentSpace;
    std::vector<std::shared_ptr<CAssessment>> mAssessments;

public:
    /**
     * @brief Constructor for CPlayer
     *
     * @param name The name of the player
     * @param motivation The initial motivation level of the player
     * @param success The initial success level of the player
     * @param yearOfStudy The initial year of study of the player
     */
    CPlayer(std::string name, int motivation, int success, int yearOfStudy);

    /**
     * @brief Constructor for CPlayer with default values
     *
     * @param name The name of the player
     */
    CPlayer(std::string name);

    /**
     * @brief Destructor for CPlayer
     */
    ~CPlayer();

    /**
     * @brief Overloaded output operator for CPlayer
     *
     * @param os The output stream
     * @param player The CPlayer object to be output
     * @return The output stream with the player's information
     */
    friend std::ostream& operator<<(std::ostream& os, const CPlayer& player);

    /**
     * @brief Set the motivation level of the player
     *
     * @param motivation The new motivation level
     */
    void SetMotivation(int motivation) { mMotivation = motivation; }

    /**
     * @brief Set the current space of the player
     *
     * @param pSpace The new current space
     */
    void SetCurrentSpace(std::shared_ptr<CSpace> pSpace);

    /**
     * @brief Set the name of the player
     *
     * @param name The new name
     */
    void SetName(const std::string& name) { mName = name; }

    /**
     * @brief Set the success level of the player
     *
     * @param success The new success level
     */
    void SetSuccess(int success);

    /**
     * @brief Set the year of study of the player
     *
     * @param yearOfStudy The new year of study
     */
    void SetYearOfStudy(int yearOfStudy) { mYearOfStudy = yearOfStudy; }

    /**
     * @brief Add an assessment to the player's completed assessments
     *
     * @param pAssessment The assessment to be added
     */
    void AddAssessment(std::shared_ptr<CAssessment>& pAssessment)
    {
        mAssessments.push_back(pAssessment);
    }

    /**
     * @brief Get the current space of the player
     *
     * @return The current space of the player
     */
    std::shared_ptr<CSpace> GetCurrentSpace();

    /**
     * @brief Get the name of the player
     *
     * @return The name of the player
     */
    std::string GetName() const { return mName; }

    /**
     * @brief Get the motivation level of the player
     *
     * @return The motivation level of the player
     */
    int GetMotivation() const { return mMotivation; }

    /**
     * @brief Get the success level of the player
     *
     * @return The success level of the player
     */
    int GetSuccess() const { return mSuccess; }

    /**
     * @brief Get the year of study of the player
     *
     * @return The year of study of the player
     */
    int GetYearOfStudy() const { return mYearOfStudy; }

    /**
     * @brief Get all the completed assessments of the player
     *
     * @return A vector of the completed assessments
     */
    std::vector<std::shared_ptr<CAssessment>> GetCompletedAssessments() const
    {
        return mAssessments;
    }

    /**
     * @brief Get the completed assessments of the player for a specific year
     *
     * @param year The year of study
     * @return A vector of the completed assessments for the specified year
     */
    std::vector<std::shared_ptr<CAssessment>> GetCompletedAssessments(int year);
};
