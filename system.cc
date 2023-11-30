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

    jsonObj["model"] = "gpt-3.5-turbo";
    json messageObj;
    messageObj["role"] = "user";
    std::string content = "Give me 10 questions in Jeopardy style. Please give me answer and fake answer";
    messageObj["content"] = content;
    std::cout << content << std::endl;
    jsonObj["messages"].push_back(messageObj);
    jsonObj["max_tokens"] = 500;
    jsonObj["temperature"] = 0;

    std::cout << "question making.." << std::endl;
    auto chat1 = openai::chat().create(jsonObj);
    std::cout << "question making complete" << std::endl;

    json data = json::parse(chat1.dump(2));
    std::string ans = data["choices"][0]["message"]["content"].get<std::string>();
    std::cout << ans << std::endl;
    
    std::istringstream iss(ans);
    std::vector<std::string> cat;
    std::vector<std::string> qu;
    std::vector<std::string> real;
    std::vector<std::string> fake;
    
    std::string line;

    while (std::getline(iss, line)) {
        if (line.find("Category:") != std::string::npos) {
            cat.push_back(line.substr(line.find(":") + 2));
            std::cout << "cat" << line.substr(line.find(":") + 2) << std::endl;
            continue;
        } else if (line.find("Real Answer:") != std::string::npos) {
            real.push_back(line.substr(line.find(":") + 2));
            std::cout << "real" << line.substr(line.find(":") + 2) << std::endl;
            continue;
        } else if (line.find("Fake Answer:") != std::string::npos) {
            fake.push_back(line.substr(line.find(":") + 2));
            std::cout << "fake" << line.substr(line.find(":") + 2) << std::endl;
            continue;
        } else if (line.find("Answer:") != std::string::npos) {
            qu.push_back(line.substr(line.find(":") + 2));
            std::cout << "qu" << line.substr(line.find(":") + 2) << std::endl;
            continue;
        } else
            continue;
    }

    for (size_t i = 0; i < answers.size(); ++i) {
        q[i]->body = qu[i];
        q[i]->answer = real[i];

        if(question_type[i])
        q[i]->fakeAnswer = fake[i];
    }

    for (int i=0; i<10; i++){
        if(i<3)
            q[i]->score = 100;
        else if(i<6)
            q[i]->score = 300;
        else if(i<9)
            q[i]->score = 500;
        else
            q[i]->score = 1000;
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

    for(int i=0; i<10; i++){
        if(!question_type[i])
            continue;


    }
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

int system::doubt()
{
    if(!question_type[cur_q])
        return 0;

    QuestionWithFakeAnswer::QuestionWithFakeAnswer current = *(q + cur_q);
    return current.determineReal(&ans);
}