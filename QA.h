#ifndef QA_H
#define QA_H
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
    // Allows for the quizVector in main to be displayed
    friend std::ostream& operator<<(std::ostream& os, const QA& qa);
};
#endif