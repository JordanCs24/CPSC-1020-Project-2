/*
My Name: Jordan Sowell
Date: 3/8/2025
Section: CPSC 1020
Description: Class of QA cpp file holds the function defintions
*/
#include "QA.h"
#include <vector>
int QA::score  = 0;

QA::QA(std::string q, std::string a){
    this->question = q;
    this->answer = a;
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
    int count = 0;
    for(std::vector<QA>::size_type i = 0; i < question.size(); i++){
        if(answer.at(i) != '\n' && answer.at(i) != ' '){
            count++;
        }
    }
    //std::cout << "Question Size: " << questionCounter << std::endl; // test for question
    for(std::vector<QA>::size_type i = 0; i < answer.size(); i++){
        if(answer.at(i) != '\n' && answer.at(i) != ' '){
            count++;
        }
    }
    //std::cout << "Answer Size: " << answerCounter << std::endl; // test for question

    return count;
}

void QA::updateScore(int val){ // Figure out what to do if score equals 0
    // Able to handle negative values
    // This runs when the score is not 0
    score += val; //Using += because if its a negative number it's just going to be switched to positive
    if(score < 0){
        score = 0;
    }
}
