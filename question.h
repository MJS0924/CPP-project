#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
    Question(const std::string& body, const std::string& answer, int score);
    ~Question();

    virtual void display() const;
    virtual const std::string& getAnswer() const;
    virtual bool determine(const std::string& userAnswer) const;

private:
    std::string body;
    std::string answer;
    int score;
};

class QuestionWithFakeAnswer : public Question {
public:
    QuestionWithFakeAnswer(const std::string& body, const std::string& answer, int score, const std::string& fakeAnswer);
    ~QuestionWithFakeAnswer();

    void display() const override;
    const std::string& getAnswer() const override;
    bool determine(const std::string& userAnswer) const override;

    void displayReal() const override;
    const std::string& getRealAnswer() const override;
    bool determineReal(const std::string& userAnswer) const override;
private:
    std::string fakeAnswer;
};

#endif // QUESTION_H