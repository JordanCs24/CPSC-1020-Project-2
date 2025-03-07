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
        
        }
        else{
            cout << "Space not found" << endl;
        }
        QA quiz(question,result);
        quizVector.push_back(quiz);
    }
    //Step 3
    //Randomly select a question and answer pair
    srand(unsigned(time(0)));
    random_shuffle(quizVector.begin(), quizVector.end());

    for(int i = 0; i < quizVector.size() - 1; ++i){
        cout << quizVector[i].getQuestion() << endl;
        cout << "Type your answer: ";
        getline(cin,userAnswer);
        if(userAnswer == quizVector[i].getAnswer()){
            quizVector[i].updateScore(1);
            cout << "Correct! Current Score: " << quizVector[i].getScore() << endl << endl;
        }else if(userAnswer != quizVector[i].getAnswer()){
            cout << "Wrong Answer! Correct Answer: " << quizVector[i].getAnswer() << endl;
            quizVector[i].updateScore(-1);
            cout << "Current Score: " << quizVector[i].getScore() << endl << endl;
        }
        userAnswer.clear();
    }
    
    cout << "Number of Questions: " << quizVector.size() - 1 << endl;
    
    
    cout << "Closing file!" << endl;
    fp.close();
    return 0;
}


/*
if lastchar of string == 
*/
//if (line[line.length()-1] == '\r')