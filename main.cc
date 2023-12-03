#include "main.h"
using json = nlohmann::json;

//system
System::System()
{
    std::cout << "How many players are there? :";
    std::cin >> player_cnt;
    getchar();
    
    players = new Player[player_cnt];
    for(int i=0; i<player_cnt; i++){
        std::string name;
        std::cout << "Please enter nickname of player" << i+1 << ": ";
        getline(std::cin, name);

        players[i].setNickname(name);
    }

    player_valid = new int[player_cnt];

    for(int i=0; i<10; i++){
        question_type[i] = 0;
    }
}

System::~System()
{
    delete [] players;
    delete [] player_valid;
    for(int i=0; i<10; i++)
        delete q[i];
}

void System::make_question()
{
    json jsonObj;

    jsonObj["model"] = "gpt-3.5-turbo";
    json messageObj;
    messageObj["role"] = "user";
    std::string content = "Give me 10 questions in Jeopardy style for player, ";
    content += players[0].getNickname();
    content += ". Please give me answer and fake answer";
    messageObj["content"] = content;
    jsonObj["messages"].push_back(messageObj);
    jsonObj["max_tokens"] = 500;
    jsonObj["temperature"] = 0;

    std::cout << "Question making.. Please wait a sec" << std::endl;
    auto chat1 = openai::chat().create(jsonObj);
    std::cout << "Question making complete!" << std::endl << std::endl;

    json data = json::parse(chat1.dump(2));
    std::string ans = data["choices"][0]["message"]["content"].get<std::string>();
    std::cout << ans << std::endl;
    
//     std::string ans = R"(
//         1. Category: History
// Answer: This famous leader led the American Revolution against British rule.
// Real Answer: Who is George Washington?
// Fake Answer: Who is Benjamin Franklin?

// 2. Category: Science
// Answer: This gas is essential for all living organisms and makes up approximately 21% of Earth's atmosphere.
// Real Answer: What is oxygen?
// Fake Answer: What is nitrogen?

// 3. Category: Movies
// Answer: This 1994 film, featuring a young lion prince, became one of Disney's most successful animated movies.
// Real Answer: What is The Lion King?
// Fake Answer: What is The Jungle Book?

// 4. Category: Geography
// Answer: This European country is known for its tulips, windmills, and wooden shoes.
// Real Answer: What is the Netherlands?
// Fake Answer: What is Denmark?

// 5. Category: Literature
// Answer: This novel, written by F. Scott Fitzgerald, explores the decadence and excess of the Jazz Age in America.
// Real Answer: What is The Great Gatsby?
// Fake Answer: What is To Kill a Mockingbird?

// 6. Category: Sports
// Answer: This legendary basketball player, known for his Air Jordan sneakers, won six NBA championships with the Chicago Bulls.
// Real Answer: Who is Michael Jordan?
// Fake Answer: Who is LeBron James?

// 7. Category: Music
// Answer: This British rock band, formed in 1970, is known for hits like "Bohemian Rhapsody" and "We Will Rock You."
// Real Answer: Who is Queen?
// Fake Answer: Who is The Rolling Stones?

// 8. Category: Food and Drink
// Answer: This popular Italian dish consists of thin, round dough topped with tomato sauce, cheese, and various toppings.
// Real Answer: What is pizza?
// Fake Answer: What is lasagna?

// 9. Category: Technology
// Answer: This company, founded by Steve Jobs, Steve Wozniak, and Ronald Wayne, revolutionized the personal computer industry.
// Real Answer: What is Apple?
// Fake Answer: What is Microsoft?

// 10. Category: Mythology
// Answer: In Greek mythology, this powerful god of the sea is often depicted with a trident and is known for causing earthquakes.
// Real Answer: Who is Poseidon?
// Fake Answer: Who is Zeus?
//     )";
    
    std::istringstream iss(ans);
    std::vector<std::string> cat;
    std::vector<std::string> qu;
    std::vector<std::string> real;
    std::vector<std::string> fake;
    
    std::string line;

    while (std::getline(iss, line)) {
        if (line.find("Category:") != std::string::npos) {
            cat.push_back(line.substr(line.find(":") + 2));
            continue;
        } else if (line.find("Real Answer:") != std::string::npos) {
            real.push_back(line.substr(line.find(":") + 2));
            continue;
        } else if (line.find("Fake Answer:") != std::string::npos) {
            fake.push_back(line.substr(line.find(":") + 2));
            continue;
        } else if (line.find("Answer:") != std::string::npos) {
            qu.push_back(line.substr(line.find(":") + 2));
            continue;
        } else
            continue;
    }

    for (size_t i = 0; i < 10; ++i) {
        question_valid[i] = 1;
        if(question_type[i]){
            QuestionWithFakeAnswer *A = new QuestionWithFakeAnswer;
            A->body = qu[i];
            A->answer = real[i];
            A->fakeAnswer = fake[i];
            q[i] = static_cast<Question *>(A);
        }
        else{
            q[i] = new Question;
            q[i]->body = qu[i];
            q[i]->answer = real[i];
        }
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
}

void System::det_question_type()
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

void System::sel_question()
{
    std::cout   << "score 100: "
                << char('X' - 9*question_valid[0]) << " " << char('X' - 9*question_valid[1]) << " " << char('X' - 9*question_valid[2]) << std::endl;
    std::cout   << "score 300: "
                << char('X' - 9*question_valid[3]) << " " << char('X' - 9*question_valid[4]) << " " << char('X' - 9*question_valid[5]) << std::endl;
    std::cout   << "score 500: "
                << char('X' - 9*question_valid[6]) << " " << char('X' - 9*question_valid[7]) << " " << char('X' - 9*question_valid[8]) << std::endl;
                
    int ans = -1;
    while(1){
        std::cout << "Please select available question(O is available question, X invalid): ";
        std::cin >> ans;
        getchar();

        if(ans <= 0 || ans > 9){
            std::cout << "Please input valid number!" << std::endl;
            continue;
        }
        else if(!question_valid[ans-1]){
            std::cout << "Please input valid question number!" << std::endl;
            continue;
        }
        else
            break;
    }
    
    this->cur_q = ans-1;
    question_valid[cur_q] = 0;
    std::cout << std::endl;
    return;
}

void System::player_answer()     //플레이어 정답 입력받기, 플레이어 번호
{
    std::string input;
    int n;
    std::cout << "Question is...\n    " << q[cur_q]->getBody() << std::endl;
    std::string ans;

    while(1){
        std::cout << "PRESS YOUR BUZZER!!!: ";
        getline(std::cin, input);

        try {
            n = std::stoi(input);

            if (n > 0 && n <= player_cnt) {
                if (player_valid[n - 1])
                    break;
                else {
                    std::cout << "You can't answer this question again.\n";
                    players[n - 1].incrementViolationCount();
                }
            } else {
                std::cout << "Please input right player number.\n";
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "Invalid input. Please enter a number.\n";
        } catch (const std::out_of_range &e) {
            std::cout << "Please input right player number.\n";
        }
    }

    this->cur_player = n-1;
    player_valid[n-1] = 0;

    std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << ": ";
    std::getline(std::cin, cur_ans);

    return;
}

int System::doubt()     //의심 성공 여부 리턴
{
    if(!question_type[this->cur_q])
        return 0;

    Question* A;
    QuestionWithFakeAnswer* B;
    A = q[cur_q];
    B = static_cast<QuestionWithFakeAnswer *>(A);
    return B->determineReal(cur_ans);
}

void System::round()
{
    int some_valid;
    do {
        player_answer();
        if(q[cur_q]->determine(cur_ans)){
            players[cur_player].addScore(q[cur_q]->score);
            std::cout << "\033[1;32m" << "\nCorrect!!" << "\033[1;0m" << std::endl;
            std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << " gets " << q[cur_q]->score << " points." << std::endl << std::endl;
            if(question_type[cur_q])
                std::cout << "You were lucky this time." << std::endl << std::endl;
            return;
        }

        char dbt;
        std::cout << "\033[1;31m" << "\nWrong!!" << "\033[1;0m" << std::endl;
        std::cout << "Do you have any doubts about the outcome?(y/n): ";
        std::cin >> dbt;
        getchar();

        if(dbt == 'y') {
            if(doubt()){
                players[this->cur_player].addScore(q[cur_q]->score*2);
                std::cout << "\033[1;32m" << "doubt success!!\n" << "\033[1;0m" ;
                std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << " gets " << 2 * q[cur_q]->score << " points." << std::endl << std::endl;
                return;
            }

            else{
                players[this->cur_player].addScore(-q[cur_q]->score);
                std::cout << "\033[1;31m" << "doubt failed!!\n" << "\033[1;0m" ;
                std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << " loses " << q[cur_q]->score << " points." << std::endl << std::endl;
            }
        }

        some_valid = 0;
        for(int i=0; i<this->player_cnt; i++)
            some_valid |= player_valid[i];

    } while(some_valid);

    //정답 인쇄
    if(question_type[cur_q]){
        Question *A = q[cur_q];
        QuestionWithFakeAnswer *B;
        B = static_cast<QuestionWithFakeAnswer *>(A);
        std::cout << "The answer is... " << B->getAnswer() << std::endl;
        std::cout << "Actually this answer is fake. Now, no one knows the real answer ¯_(ツ)_/¯" << std::endl << std::endl;
    }
    else{
        std::cout << "The answer is... " << q[cur_q]->getAnswer() << std::endl << std::endl;
    }
    return;
}

void System::finalRound()
{
    cur_q = 9;
    int some_valid;

    do {
        player_answer();
        if(q[cur_q]->determine(cur_ans)){
            players[cur_player].addScore(q[cur_q]->score);
            std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << " gets " << q[cur_q]->score << " points." << std::endl << std::endl;
            if(question_type[cur_q])
                std::cout << "You were lucky this time." << std::endl << std::endl;
            return;
        }

        char dbt;
        std::cout << "\033[1;31m" << "\nWrong!!" << "\033[1;0m" << std::endl;
        std::cout << "Do you have any doubts about the outcome?(y/n): ";
        std::cin >> dbt;
        std::cout << std::endl << std::endl;
        getchar();

        if(dbt == 'y') {
            if(doubt()){
                players[this->cur_player].addScore(q[cur_q]->score*2);
                std::cout << "doubt success!!\n";
                std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << " gets " << 2 * q[cur_q]->score << "points." << std::endl << std::endl;
                return;
            }

            else{
                players[this->cur_player].addScore(-q[cur_q]->score);
                std::cout << "doubt failed!!\n";
                std::cout << "\033[1;33m" << players[cur_player].getNickname() << "\033[1;0m" << " loses " << q[cur_q]->score << "points." << std::endl << std::endl;
            }
        }

        some_valid = 0;
        for(int i=0; i<this->player_cnt; i++)
            some_valid |= player_valid[i];

    } while(some_valid);

    //정답 인쇄
    if(question_type[cur_q]){
        Question *A = q[cur_q];
        QuestionWithFakeAnswer *B;
        B = static_cast<QuestionWithFakeAnswer *>(A);
        std::cout << "The answer is.." << B->getAnswer() << std::endl;
        std::cout << "Actually this answer is fake. Now, no one knows the real answer ¯_(ツ)_/¯" << std::endl << std::endl;
    }
    else{
        std::cout << "The answer is.." << q[cur_q]->getAnswer() << std::endl << std::endl;
    }
    return;
}

void System::reset_player_valid()
{
    for(int i=0; i<player_cnt; i++)
        player_valid[i] = 1;
    return;
}

void System::printScores()
{
    int max = players[0].getScore();
    std::vector<int> num;

    for(int i=0; i<player_cnt; i++){
        std::cout << "\033[1;33m" << players[i].getNickname() << "\033[1;0m" << ": " << players[i].getScore() << std::endl;

        if(max < players[i].getScore())
            max = players[i].getScore();
    }

    for(int i=0; i<player_cnt; i++){
        if(players[i].getScore() == max)
            num.push_back(i);
    }

    std::cout << std::endl << "The first place is..";
    for(unsigned int i=0; i<num.size(); i++){
        std::cout << "\033[1;33m" << players[ num[i] ].getNickname() << "\033[1;0m" ;
        if(i != num.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl << std::endl;
    return;
}

int main()
{
    System newGame;
    newGame.det_question_type();
    newGame.make_question();
    for(int i=0; i<9; i++){
        std::cout << "===================Round " << i+1 << "===================" << std::endl;
        newGame.reset_player_valid();
        newGame.sel_question();
        newGame.round();
    }

    std::cout << "The results so far are.." << std::endl;
    newGame.printScores();

    std::cout << "===================Final Round===================" << std::endl;
    newGame.reset_player_valid();
    newGame.finalRound();

    std::cout << "The Final result is.." << std::endl;
    newGame.printScores();
    std::cout << "Congratulation!!" << std::endl;
}