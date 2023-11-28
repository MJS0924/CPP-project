#include "system.h"

system::system()
{
    cout << "How many player is there? :";
    cin >> num;
    
    players = new player::player[num];
    player_valid = new int[num];

    for(int i=0; i<10; i++){
        q[i] = new question::question;
        question_type[i] = 0;
    }
}

system::~system()
{
    delete [] players;
    delete [] player_valid;
    for(int i=0; i<10; i++)
        delete q[i];
}

void system::make_question()
{
    auto chat1 = openai::chat().create(R"(
        {
        "model": "gpt-3.5-turbo",
        "messages":[{"role":"user", "content":"When the difficulty level is 0 to 10, give me 3 question in Jeopardy style corresponding to 3"}],
        "max_tokens": 300,
        "temperature": 0
    }
    )"_json);
    std::string dif_3 = chat1.dump(2);

    chat1 = openai::chat().create(R"(
        {
        "model": "gpt-3.5-turbo",
        "messages":[{"role":"user", "content":"When the difficulty level is 0 to 10, give me 3 question in Jeopardy style corresponding to 5"}],
        "max_tokens": 300,
        "temperature": 0
    }
    )"_json);
    std::string dif_6 = chat1.dump(2);

    chat1 = openai::chat().create(R"(
        {
        "model": "gpt-3.5-turbo",
        "messages":[{"role":"user", "content":"When the difficulty level is 0 to 10, give me 3 question in Jeopardy style corresponding to 7"}],
        "max_tokens": 300,
        "temperature": 0
    }
    )"_json);
    std::string dif_9 = chat1.dump(2);

    chat1 = openai::chat().create(R"(
        {
        "model": "gpt-3.5-turbo",
        "messages":[{"role":"user", "content":"When the difficulty level is 0 to 10, give me 3 question in Jeopardy style corresponding to 10"}],
        "max_tokens": 300,
        "temperature": 0
    }
    )"_json);
    std::string dif_10 = chat1.dump(2);

    return;
}

void system::det_question_type()
{
    int a, b, c;
    srand((unsigned int)time(nullptr));
    a = rand() % 9;
    b = rand() % 8;
    c = rand() % 7;

    if (b >= a) b++;
    if (b < a){
        if (c >= b) c++;
        if (c >= a) c++;
    }
    else{
        if (c >= a) c++;
        if (c >= b) c++;
    }

    question_type[a] = 1;
    question_type[b] = 1;
    question_type[c] = 1;
    
    a = rand();
    if(a <= 25600)
        question_type[9] = 1;
}

int system::sel_question()
{
    std::cout   << "score 100: "
                << question_valid[0]; << question_valid[1] << question_valid[2] << std::endl;
    std::cout   << "score 200: "
                << question_valid[3]; << question_valid[4] << question_valid[5] << std::endl;
    std::cout   << "score 300: "
                << question_valid[6]; << question_valid[7] << question_valid[8] << std::endl;
    
    std::cout << "Please select a question(O is available question, X invalid).: ";
    int ans;
    std::cin >> ans;
    return ans;
}

std::string system::player_answer()
{
    int n;
    std::string ans;
    std::cout << "PRESS YOUR BUZZER!!!" << std::endl;
    cin << n;

    std::cout << "ans: ";
    std::cin >> ans;
    player_valid[n] = 0;

    return ans;
}

int system::check_ans(std::string ans)
{

}