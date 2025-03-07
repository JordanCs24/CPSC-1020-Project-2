/*
My Name: Jordan Sowell
Date: 3/8/2025
Section: CPSC 1020
Time: 1 hour
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
    for(std::vector<QA>::size_type i = 0; i < question.size(); i++){ // Allows for proper handling of the vector question
        if(answer.at(i) != '\n' && answer.at(i) != ' '){ // Variable count gets incremented if the character is anything but a newline and space
            count++;
        }
    }
    for(std::vector<QA>::size_type i = 0; i < answer.size(); i++){ // Allows for proper handling of the vector question
        if(answer.at(i) != '\n' && answer.at(i) != ' '){ // Variable count gets incremented if the character is anything but a newline and space
            count++;
        }
    }

    return count;
}

void QA::updateScore(int val){
    score += val; // Add and subtracts the value 
    if(score < 0){ // Doesn't allow for negative numbers
        score = 0;
    }
}
