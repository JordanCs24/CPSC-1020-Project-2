/*
My Name: Jordan Sowell
Date: 3/8/2025
Section: CPSC 1020
Time: 5+ hours
Description: A program that allows a player to answer quiz questions. The game allows
adding questions and answers to a database in a simple text file. The program
asks the questions in the database in random order. The player types an answer
and hits enter. If the answer is correct, the player is told so and the player earns
1 point. If the answer is incorrect, the player is told so and the players loses 1
point. Once all questions have been asked, the program displays how many
questions have been asked, the number of correct answers, the number of wrong
answers, and the player’s final score.
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <random>
#include "buildResultString.h"
#include "QA.h"

using namespace std;

int main(int argc, char *argv[]){
    ifstream fp;
    int questionAmount = 0; // Made to check how many questions there are total
    int amountCorrect = 0; // Checks how many questions the user got correct
    int amountWrong = 0; // Checks how many questions the user got wrong
    string question; // Holds the string value of each question 
    string correctAnswer; // Holds the correct Answer value for the quiz
    string userAnswer; // What the user an
    vector<QA> quizVector; // List for each question and answer pair
    
    fp.open(argv[1]);
    if(!fp.is_open()){
        cout << "File: " << argv[1] << " could not be opened" << endl; 
        return 1;
    }

    while(getline(fp, question) && getline(fp, correctAnswer)){ // Reads in the contents of the data file
        string result; // holds the correct results after white space in answer
        size_t pos = correctAnswer.find(" "); // holds the position where there is a space located
        size_t rPos = correctAnswer.find("\r"); // Holds the position where there is a carriage located

        if (pos != std::string::npos) {
            result = correctAnswer.substr(pos+1,rPos - pos - 1); // Extracts the substring after the delimiter
        }else{
            cout << "Space not found" << endl;
        }
        QA quiz(question,result);
        quizVector.push_back(quiz); // pushes quiz into the quizVector list
        ++questionAmount; 
    }
    
    //Randomly select a question and answer pair
    srand(unsigned(time(0)));
    random_shuffle(quizVector.begin(), quizVector.end());
    for(int i = 0; i < questionAmount; ++i){
        cout << quizVector[i].getQuestion() << endl;
        cout << "Type your answer: ";
        getline(cin,userAnswer);
        if(userAnswer == quizVector[i].getAnswer()){
            quizVector[i].updateScore(1);
            cout << "Correct! Current Score: " << quizVector[i].getScore() << endl << endl;
            ++amountCorrect;
        }else if(userAnswer != quizVector[i].getAnswer()){
            cout << "Wrong Answer! Correct Answer: " << quizVector[i].getAnswer() << endl;
            quizVector[i].updateScore(-1);
            cout << "Current Score: " << quizVector[i].getScore() << endl << endl;
            ++amountWrong;
        }
        userAnswer.clear();
    }
    
    // Puts into the console How many questions was asked, what the user got correct, what they got wrong, and their final score.
    cout << buildResultString(questionAmount,amountCorrect,amountWrong);
    
    fp.close(); // Closes the input file
    return 0;
}