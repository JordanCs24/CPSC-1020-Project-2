#include "buildResultString.h"
#include "QA.h"
/*
buildResultString must use a stringstream to build and return a string.
• The number of questions, correct answers, and wrong answers are
passed as arguments to the functions.
• Make buildResultString a friend of class QA so that the function can
access the static variable score.
• The function should be declared and implemented in files
buildResultString .h and buildResultString .cpp,
respectively.
*/

std::string buildResultString(int questions, int correct, int wrong){
    std::stringstream ss;
    
    ss << "Number of questions: " << questions << "\n";
    ss << "Number correct answers: " << correct << "\n";
    ss << "Number wrong answers: " << wrong << "\n";
    ss << "Final score: " << QA::score << "\n";
    return ss.str();
}