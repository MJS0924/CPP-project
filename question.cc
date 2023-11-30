#include "question.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <openai/openai.h>

using json = nlohmann::json;

Question::Question(const std::string& body, const std::string& answer, int score)
    : body_(body), answer_(answer), score_(score) {}

Question::~Question() {}

const std::string& Question::getBody() const {
    return body;
}

const std::string& Question::getAnswer() const {
    return answer;
}

int Question::determine(const std::string& userAnswer) const {
    json jsonObj;
    jsonObj["model"] = "gpt-3.5-turbo";

    std::string content = "Rate the similarity between the answers to the following two questions on a scale of 0 to 10. Provide the answer in numerical form only. 1. ";
    content += userAnswer + " 2. " + answer;

    json messageObj;
    messageObj["role"] = "user";
    messageObj["content"] = content;
    jsonObj["messages"].push_back(messageObj);

    jsonObj["max_tokens"] = 10;
    jsonObj["temperature"] = 0;

    auto chatResponse = openai::chat().create(jsonObj);
    json data = json::parse(chatResponse.dump(2));

    std::string similarityScoreStr = data["choices"][0]["message"]["content"].get<std::string>();
    int similarity = std::stoi(similarityScoreStr);
    if(similarity < 8) return false;
    return true;
}

QuestionWithFakeAnswer::QuestionWithFakeAnswer(const std::string& body, const std::string& answer, int score, const std::string& fakeAnswer)
    : Question(body, answer, score), fakeAnswer_(fakeAnswer) {}

QuestionWithFakeAnswer::~QuestionWithFakeAnswer() {}

const std::string& QuestionWithFakeAnswer::getAnswer() const {
    return fakeAnswer;
}

bool QuestionWithFakeAnswer::determine(const std::string& userAnswer) const {
    json jsonObj;
    jsonObj["model"] = "gpt-3.5-turbo";

    std::string content = "Rate the similarity between the answers to the following two questions on a scale of 0 to 10. Provide the answer in numerical form only. 1. ";
    content += userAnswer + " 2. " + fakeAnswer;

    json messageObj;
    messageObj["role"] = "user";
    messageObj["content"] = content;
    jsonObj["messages"].push_back(messageObj);

    jsonObj["max_tokens"] = 10;
    jsonObj["temperature"] = 0;

    auto chatResponse = openai::chat().create(jsonObj);
    json data = json::parse(chatResponse.dump(2));

    std::string similarityScoreStr = data["choices"][0]["message"]["content"].get<std::string>();
    int similarity = std::stoi(similarityScoreStr);
    if(similarity < 8) return false;
    return true;
}

void QuestionWithFakeAnswer::displayReal() const {
    std::cout << "Answer: " << answer << std::endl;
}

const std::string& QuestionWithFakeAnswer::getRealAnswer() const {
    return answer;
}

bool QuestionWithFakeAnswer::determineReal(const std::string& userAnswer) const {
    json jsonObj;
    jsonObj["model"] = "gpt-3.5-turbo";

    std::string content = "Rate the similarity between the answers to the following two questions on a scale of 0 to 10. Provide the answer in numerical form only. 1. ";
    content += userAnswer + " 2. " + answer;

    json messageObj;
    messageObj["role"] = "user";
    messageObj["content"] = content;
    jsonObj["messages"].push_back(messageObj);

    jsonObj["max_tokens"] = 10;
    jsonObj["temperature"] = 0;

    auto chatResponse = openai::chat().create(jsonObj);
    json data = json::parse(chatResponse.dump(2));

    std::string similarityScoreStr = data["choices"][0]["message"]["content"].get<std::string>();
    int similarity = std::stoi(similarityScoreStr);
    if(similarity < 8) return false;
    return true;
}
