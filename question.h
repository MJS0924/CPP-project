#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
    Question(const std::string& body, const std::string& answer, int score);
    Question() {};
    ~Question();

    const std::string& getBody() const;
    virtual const std::string& getAnswer() const;
    virtual bool determine(std::string& userAnswer) const;

    friend class system;

private:
    std::string body;
    std::string answer;
    int score;
};

class QuestionWithFakeAnswer : public Question {
public:
    QuestionWithFakeAnswer(const std::string& body, const std::string& answer, int score, const std::string& fakeAnswer);
    ~QuestionWithFakeAnswer();

    const std::string& getAnswer() const override;
    bool determine(std::string& userAnswer) const override;

    void displayReal() const;
    const std::string& getRealAnswer() const;
    bool determineReal(std::string& userAnswer) const;

    friend class system;

private:
    std::string fakeAnswer;
};

#endif // QUESTION_H