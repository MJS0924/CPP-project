#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& nickname, int score);
    Player() {};
    ~Player();

    void display() const;
    const std::string& getNickname() const;
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

#endif // PLAYER_H
