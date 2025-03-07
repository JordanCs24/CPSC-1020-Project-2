#ifndef QA_H
#define QA_H
#include "buildResultString.h"
#include <string>
#include <iostream>

class QA{
private: 
    std::string question;
    std::string answer;
    static int score;
public:
    QA() : question(""), answer(""){};
    QA(std::string q, std::string a);
    std::string getQuestion ()const;
    std::string getAnswer()const;
    static int getScore();
    int letterCount();
    static void updateScore(int val);
    friend std::string buildResultString(int questions, int correct, int wrong);
};
#endif