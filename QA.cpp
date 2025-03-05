#include "QA.h"
int QA::score  = 0;

QA::QA(std::string q, std::string a){
    question = q;
    answer = a;
}
std::string QA::getQuestion()const{
    return question;
}
std::string QA::getAnswer()const{
    return this->answer;
}
int QA::getScore(){
    return score;
}
int QA::letterCount(){
    int questionCounter = 0;
    int answerCounter = 0;
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
    return (questionCounter + answerCounter);
}

void QA::updateScore(int val){
    if(val > 0){
        score += val;
    }
    else if(val < 0){
        // Able to handle negative values
        score += val; //Using += because if its a negative number it's just going to be switched to positive
    }
}