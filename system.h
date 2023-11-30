#include <random>
#include <iostream>
#include <ctime>
#include "openai.hpp"
#include "player.h"
#include "question.h"

class system
{
    public:
        system();
        ~system();

        void make_question();           //make question
        void det_question_type();       //select the question_type
        int sel_question();             //player selects question to answer    
        std::string player_answer();    //player inputs answer
        int doubt();                    //return whether doubt success

    private:
        int num;
        player::player *players;
        int *player_valid;

        std::string category;
        question::question *q[10];
        int question_valid[9];
        int question_type[10];      //0: ordinary, 1: doubt

        int cur_q;
};