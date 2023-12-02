#include <random>
#include <iostream>
#include <ctime>
#include "openai.hpp"

class Question {
public:
    Question();
    ~Question();

    const std::string& getBody() const;
    virtual const std::string& getAnswer() const;
    virtual bool determine(std::string& userAnswer) const;

    friend class System;

protected:
    std::string body;
    std::string answer;
    int score;
};

class QuestionWithFakeAnswer : public Question {
public:
    QuestionWithFakeAnswer();
    ~QuestionWithFakeAnswer();

    const std::string& getAnswer() const override;
    bool determine(std::string& userAnswer) const override;

    const std::string& getRealAnswer() const;
    bool determineReal(std::string& userAnswer) const;

    friend class System;

private:
    std::string fakeAnswer;
};

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

//system=========================================================================
class System {
public:
    System();
    ~System();

    void make_question();           //make question
    void det_question_type();       //select the question_type
    void sel_question();            //player selects question to answer

    void player_answer();           //player inputs answer
    int doubt();                    //return whether doubt success
    void round();
    void finalRound();
    void reset_player_valid();
    
    void printScores();

private:
    int player_cnt;
    Player *players;
    int *player_valid;

    Question *q[10];
    int question_valid[9];
    int question_type[10];      //0: ordinary, 1: doubt

    int cur_player;
    int cur_q;
    std::string cur_ans;
};