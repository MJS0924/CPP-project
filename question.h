#ifndef QUESTION_H
#define QUESTION_H

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

#endif