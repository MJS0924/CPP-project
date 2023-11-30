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

    cout << "Please enter the desired topic(e.g math, history): ";
    cin >> category;

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
    json jsonObj;

    for(int i=0; i<10; i++){
        jsonObj["model"] = "gpt-3.5-turbo";
        json messageObj;
        messageObj["role"] = "user";
        std::string content = "When the difficulty level is 0 to 10, give me a question in Jeopardy style corresponding to difficulty"
        
        if(i < 3)
            content += "3";
        else if(i < 6)
            content += "5";
        else if(i < 9)
            content += "9";
        else
            content += "10";

        content += ". Please give me the answer too. The category is ";
        content += category;
        messageObj["content"] = content;
        jsonObj["messages"].push_back(messageObj);
        jsonObj["max_tokens"] = 300;
        jsonObj["temperature"] = 0;

        auto chat1 = openai::chat().create(jsonObj);

        std::cout << chat1.dump(2) << std::endl;

        json data = json::parse(chat1.dump(2));
        std::string ans = data["choices"][0]["message"]["content"].get<std::string>();

        std::size_t found = ans.find("Answer:");
        if (found != std::string::npos) {
            std::size_t endOfAnswer = ans.find("\n", found);
            if (endOfAnswer != std::string::npos) {
                std::string answerPart = ans.substr(found + 8, endOfAnswer - (found + 8));
                std::cout << "Answer Part: " << answerPart << std::endl;
            }
        }
        found = ans.find("Question:");
        if (found != std::string::npos) {
            std::string questionPart = ans.substr(found + 10);
            std::cout << "Question Part: " << questionPart << std::endl;
        }
    }
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
                
    int ans = -1;
    while(ans < 0 || ans >= 9 || !question_valid[ans]){
        std::cout << "Please select available question(O is available question, X invalid): ";
        std::cin >> ans;
    }
    
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

int system::check_ans(int q_num, std::string ans)
{
    json jsonObj;

    std::string content = "Rate the similarity between the answers to the following two questions on a scale of 0 to 10. Provide the answer in numerical form only. 1. ";
    content = content + ans;
    content = content + " 2. ";
    content = content + "Who is Albert Einstein?";

    jsonObj["model"] = "gpt-3.5-turbo";
    json messageObj;
    messageObj["role"] = "user";
    messageObj["content"] = content;
    jsonObj["messages"].push_back(messageObj);
    jsonObj["max_tokens"] = 10;
    jsonObj["temperature"] = 0;

    auto chat1 = openai::chat().create(jsonObj);

    std::cout << chat1.dump(2) << std::endl;

    json data = json::parse(chat1.dump(2));
    std::string ans = data["choices"][0]["message"]["content"].get<std::string>();
    std::cout << ans << std::endl;

    return std::stoi(ans);
}