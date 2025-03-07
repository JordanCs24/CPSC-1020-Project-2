/*
My Name: Jordan Sowell
Date: 3/8/2025
Section: CPSC 1020
Time: 20 minutes
Description: 
*/
#include "buildResultString.h"
#include "QA.h"

std::string buildResultString(int questions, int correct, int wrong){
    std::stringstream ss;
    
    ss << "Number of questions: " << questions << "\n";
    ss << "Number correct answers: " << correct << "\n";
    ss << "Number wrong answers: " << wrong << "\n";
    ss << "Final score: " << QA::score << "\n";
    return ss.str(); // Returns the entire input that was put into the string stream of ss
}