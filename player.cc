#include "player.h"
#include <iostream>

Player::Player(const std::string& nickname, int score)
    : nickname(nickname), score(score), violationCount(0) {}

Player::~Player() {
    std::cout << "Player destructor called" << std::endl;
}

void Player::display() const {
    std::cout << "Nickname: " << nickname_ << std::endl;
    std::cout << "Score: " << score_ << std::endl;
    std::cout << "Violation Count: " << violationCount_ << std::endl;
}

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
}

void Player::addScore(int n){
    score += n;
}