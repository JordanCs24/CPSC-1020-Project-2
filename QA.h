#ifndef QA_H
#define QA_H
#include "string"
using namespace std;
class QA{
private: 
    string question;
    string answer;
    int static score;
public:
    QA() : question(""), answer(""){};
    QA(string q, string a);
    string getQuestion();
    string getAnswer();
    int static getScore();
    int letterCount();
    void static updateScore(int val);

};
#endif