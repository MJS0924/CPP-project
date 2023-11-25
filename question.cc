#include "question.h"

question::question (int score, string::string cat) : score(score), cat(cat)
{
    //get question about category from API
    //set difficulty by score

    return;
}

int question::check (string::string ans)
{
    //check if the answer is yes

    return 1;
}

void question::printQ (int num)
{
    std::cout << num << ". " << Q << endl;

    return;
}

int question::getscore ()
{
    return score;
}