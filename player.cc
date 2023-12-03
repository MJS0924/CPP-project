#include "player.h"
using json = nlohmann::json;

//player
Player::Player() 
{
    score = 0;
    violationCount = 0;
};

Player::~Player() {}

const std::string& Player::getNickname() const {
    return nickname;
}

int Player::getScore() const {
    return score;
}

int Player::getViolationCount() const {
    return violationCount;
}

void Player::incrementViolationCount() {
    ++violationCount;
    if(violationCount >= 3){
        score -= 100;
        std::cout << "\033[1;33m" << nickname << "\033[1;0m" << ", Your violation count is " << "\033[1;31m" << violationCount << "\033[1;0m" << ". You lose 100 points (╯°益°)╯彡" << std::endl;
    }
}

void Player::addScore(int n){
    score += n;
}