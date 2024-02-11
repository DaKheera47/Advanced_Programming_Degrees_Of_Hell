#pragma once

#include <iostream>

class CPlayer
{
private:
    std::string mName;
    int mAge;

public:
    CPlayer(std::string name, int age);
    ~CPlayer();

    std::string getName();
    int getAge();
};
