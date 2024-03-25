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
    std::vector<std::shared_ptr<CAssessment>> mCompletedAssessments;
    std::vector<std::shared_ptr<CAssessment>> mDeferredAssessments;

    bool mHasWon = false;
    bool mHasDroppedOut = false;

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
     * @brief Defer an assessment
     *
     * @param pAssessment The assessment to be deferred
     */
    void DeferAssessment(std::shared_ptr<CAssessment>& pAssessment);

    /**
     * @brief Defer assessments to reach a specified level of motivation.
     *
     * Defers the player's completed assessments, starting from
     * those with the lowest motivational
     * cost, to increase the player's motivation to the specified target.
     *
     * @param targetMotivation The motivation level that the player aims to reach by deferring
     * assessments.
     * @return true if the target motivation level is reached by deferring assessments, false if the
     * target motivation cannot be reached due to running out of assessments to defer
     * false if the target motivation level cannot be reached with just deferring assessments
     */
    bool DeferAssessmentsToGetMotivation(int targetMotivation);

    /**
     * @brief Re-complete a previously deferred assessment
     *
     * @param pAssessment The deferred assessment to be re-completed
     */
    void ResubmitDeferredAssessment();

    /**
     * @brief Get all the deferred assessments of the player
     *
     * @return A vector of the deferred assessments
     */
    std::vector<std::shared_ptr<CAssessment>> GetDeferredAssessments() const
    {
        return mDeferredAssessments;
    }

    /**
     * @brief apply for MC, if the player is eligible
     *
     * in the current implementation, all players are eligible for MC, and will be accepted
     *
     * @return true if the player is eligible for MC, false otherwise
     */
    bool ApplyForMC();

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
     * @brief Set the has won status of the player
     *
     * @param hasWon The new has won status
     */
    void SetHasWon(bool hasWon) { mHasWon = hasWon; }

    /**
     * @brief Set the has dropped out status of the player
     *
     * @param hasDroppedOut The new has dropped out status
     */
    void SetDroppedOut(bool hasDroppedOut) { mHasDroppedOut = hasDroppedOut; }

    /**
     * @brief Add an assessment to the player's completed assessments
     *
     * @param pAssessment The assessment to be added
     */
    void AddAssessment(std::shared_ptr<CAssessment>& pAssessment)
    {
        mCompletedAssessments.push_back(pAssessment);
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
     * @brief Get the has dropped out status of the player
     *
     * @return The has dropped out status of the player
     */
    bool GetHasDroppedOut() const { return mHasDroppedOut; }

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
     * @brief has the player won the game
     *
     * @return true if the player has won the game
     */
    bool GetHasWon() const { return mHasWon; }

    /**
     * @brief Get all the completed assessments of the player
     *
     * @return A vector of the completed assessments
     */
    std::vector<std::shared_ptr<CAssessment>> GetCompletedAssessments() const
    {
        return mCompletedAssessments;
    }

    /**
     * @brief Get the completed assessments of the player for a specific year
     *
     * @param year The year of study
     * @return A vector of the completed assessments for the specified year
     */
    std::vector<std::shared_ptr<CAssessment>> GetCompletedAssessments(int year);

    /**
     * @brief handle deferred assessments at the end of each round
     */
    void HandleDeferredAssessments();
};
