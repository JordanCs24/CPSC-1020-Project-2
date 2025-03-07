/*
My Name: Jordan Sowell
Date: 3/8/2025
Section: CPSC 1020
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
    int amountCorrect = 0;
    int amountWrong = 0;
    string question;
    string correctAnswer;
    string userAnswer;
    vector<QA> quizVector;
    
    fp.open(argv[1]);
    if(!fp.is_open()){
        cout << "File: " << argv[1] << " could not be opened" << endl;
    }

    while(!fp.eof()){ // Reads in the contents of the database.txt file
        string result;
        getline(fp, question);
        getline(fp, correctAnswer);
        size_t pos = correctAnswer.find(" "); // holds the position where there is a space located
        size_t rPos = correctAnswer.find("\r");
        //correctAnswer.erase(0,pos);
        if (pos != std::string::npos) { // FIX: Correct Answers aren't marked as correct
        // Extract the substring after the delimiter
        result = correctAnswer.substr(pos+1,rPos - pos - 1);
        
        }else{
            cout << "Space not found" << endl;
        }
        QA quiz(question,result);
        quizVector.push_back(quiz);
    }
    //Step 3
    //Randomly select a question and answer pair
    srand(unsigned(time(0)));
    random_shuffle(quizVector.begin(), quizVector.end());

    for(vector<QA>::size_type i = 0; i < quizVector.size(); ++i){
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

    //cout << "Number of Questions: " << quizVector.size() - 1 << endl;
    //Step 4: Create Build String in cpp file and implement it
    
    cout << buildResultString(quizVector.size(),amountCorrect,amountWrong);
    
    fp.close();
    return 0;
}


/*
if lastchar of string == 
*/
//if (line[line.length()-1] == '\r')