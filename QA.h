#ifndef QA_H
#define QA_H
#include "string"

class QA{
private: 
    std::string question;
    std::string answer;
    int static score;
public:
    QA() : question(""), answer(""){};
    QA(std::string q, std::string a);
    std::string getQuestion();
    std::string getAnswer();
    int static getScore();
    int letterCount();
    void static updateScore(int val);

};
#endif