#pragma once

#include "./spaces/CAssessment.h"
#include "CSpace.h"

class CUtils
{
public:
    /**
     * @brief Reads lines from a file and returns them as a vector of strings.
     * @param[in] filePath The path to the file to be read.
     * @return A vector containing the lines read from the file.
     */
    static std::vector<std::string> ReadFileLines(const std::string& filePath);

    /**
     * @brief Splits a string based on a delimiter and returns the tokens as a vector.
     * @param[in] s The string to be split.
     * @param[in] delimiter The character used as a delimiter for splitting.
     * @return A vector containing the split tokens.
     */
    static std::vector<std::string> Split(const std::string& s, char delimiter);

    /**
     * @see https://stackoverflow.com/a/58090517
     * @brief Strips whitespace from the beginning and end of a string.
     * @param[in,out] str The string to be stripped.
     * @return The stripped string.
     */
    static std::string Strip(std::string& str);

    /**
     * @see https://stackoverflow.com/a/3418285
     * @brief Replaces occurrences of a substring within a string with another substring.
     * @param[in,out] str The original string.
     * @param[in] from The substring to be replaced.
     * @param[in] to The substring to replace with.
     */
    static void Replace(std::string& str, const std::string& from, const std::string& to);

    /**
     * @brief Converts a character to an integer.
     * @param[in] c The character to be converted.
     * @return The integer representation of the character.
     */
    static int CharToInt(const char& c);

    /**
     * @brief Converts a string to an integer.
     * @param[in] str The string to be converted.
     * @return The integer representation of the string.
     */
    static int StrToInt(const std::string& str);

    /**
     * @brief Generates a random integer. Overloaded to provide different ranges.
     * @return A random integer.
     */
    static int RandInt();

    /**
     * @brief Generates a random integer within a range [0, end).
     * @param[in] end The upper limit of the range.
     * @return A random integer within the specified range.
     */
    static int RandInt(int end);

    /**
     * @brief Generates a random integer within a range [start, end).
     * @param[in] start The lower limit of the range.
     * @param[in] end The upper limit of the range.
     * @return A random integer within the specified range.
     */
    static int RandInt(int start, int end);

    /**
     * @see https://stackoverflow.com/a/571405
     * @brief Checks if an item is present in a given vector.
     * @param[in] vec The vector to search through.
     * @param[in] item The item to search for.
     * @return True if the item is present in the vector, false otherwise.
     */
    template <typename T>
    static bool PresentInVector(const std::vector<T>& vec, const T& item);

    /**
     * @brief Gets the index of a space object in a vector of shared pointers to CSpace objects.
     * @param[in] spaces The vector of shared pointers to CSpace objects.
     * @param[in] pCurrentSpace A shared pointer to the CSpace object to find.
     * @return The index of the space object in the vector, or -1 if not found.
     */
    static int GetSpaceIndex(const std::vector<std::shared_ptr<CSpace>>& spaces,
                             std::shared_ptr<CSpace>& pCurrentSpace);

    /**
     * @brief sorts the assessments by motivation cost, to be used in sorting
     *
     * @param a Shared pointer to the first assessment
     * @param b Shared pointer to the second assessment
     **/
    static bool compareAssessments(const std::shared_ptr<CAssessment>& a,
                                   const std::shared_ptr<CAssessment>& b);
};
