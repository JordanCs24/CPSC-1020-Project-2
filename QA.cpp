#include "QA.h"

QA::QA(std::string q, std::string a){
    question = q;
    answer = a;
}
int QA::getScore(){
    return score;
}
int QA::letterCount(){
    int questionCounter, answerCounter;
    for(int i = 0; i < question.size(); i++){
        if(isalpha(question.at(i))){
            questionCounter++;
        }
    }
    for(int i = 0; i < answer.size(); i++){
        if(isalpha(answer.at(i))){
            answerCounter++;
        }
    }
}