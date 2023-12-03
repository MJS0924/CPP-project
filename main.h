#ifndef MAIN_H
#define MAIN_H

#include <random>
#include <iostream>
#include <ctime>
#include "openai.hpp"
#include "question.h"
#include "player.h"

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

#endif