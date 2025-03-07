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
    for(int i = 0; i < question.size() - 1; i++){
        if(answer.at(i) != '\n' && answer.at(i) != ' '){
            questionCounter++;
        }
    }
    //std::cout << "Question Size: " << questionCounter << std::endl; // test for question
    for(int i = 0; i < answer.size() - 1; i++){
        if(answer.at(i) != '\n' && answer.at(i) != ' '){
            answerCounter++;
        }
    }
    //std::cout << "Answer Size: " << answerCounter << std::endl; // test for question

    return questionCounter;
}

void QA::updateScore(int val){ // Figure out what to do if score equals 0
    // Able to handle negative values
    // This runs when the score is not 0
    score += val; //Using += because if its a negative number it's just going to be switched to positive
    if(score < 0){
        score = 0;
    }
}
