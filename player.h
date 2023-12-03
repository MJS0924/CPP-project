#ifndef PLAYER_H
#define MAIN_H

#include <random>
#include <iostream>
#include <ctime>
#include "openai.hpp"

class Player {
public:
    Player();
    ~Player();

    const std::string& getNickname() const;
    void setNickname(std::string name){
        nickname = name;
    }
    int getScore() const;
    int getViolationCount() const;
    void incrementViolationCount();
    void addScore(int n);

    friend class system;

private:
    std::string nickname;
    int score;
    int violationCount;
};

#endif