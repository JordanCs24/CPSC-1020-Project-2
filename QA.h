/*
My Name: Jordan Sowell
Date: 3/8/2025
Section: CPSC 1020
Time: 30 minutes 
Description: Header file of the QA class. It holds the function declarations of the class
*/
#ifndef QA_H
#define QA_H
#include "buildResultString.h"
#include <string>

class QA{
private: 
    std::string question;
    std::string answer;
    static int score;
public:
    QA() : question(""), answer(""){}; // default constructor
    QA(std::string q, std::string a); 
    std::string getQuestion ()const;
    std::string getAnswer()const;
    static int getScore();
    int letterCount();
    static void updateScore(int val);
    friend std::string buildResultString(int questions, int correct, int wrong);
};
#endif