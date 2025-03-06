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
/*
    QA Test; // Testing update score function
    cout << "Testing QA update score" << endl;
    Test.updateScore(-1);
    cout << "Score: " << Test.getScore() << endl;
*/
    ifstream fp; 
    int score; 
    string question;
    string correctAnswer;
    string userAnswer;
    vector<QA> quizVector;
    
    fp.open(argv[1]);
    if(!fp.is_open()){
        cout << "File: " << argv[1] << " could not be opened" << endl;
    }
    cout << "File was opened" << endl << endl;
    if(fp.eofbit)
    while(!fp.eof()){ // Reads in the contents of the database.txt file
        getline(fp, question);
        getline(fp, correctAnswer);
        QA quiz(question,correctAnswer);
        quizVector.push_back(quiz);
    }
    //Step 3
    //Randomly select a question and answer pair
    srand(unsigned(time(0)));
    random_shuffle(quizVector.begin(), quizVector.end());

    cout << endl << "After Sort: " << endl << endl;
    for(int i = 0; i < quizVector.size(); ++i){
        cout << quizVector[i].getQuestion() << endl;
        cout << "Type your answer: ";
        cin.ignore();
        

        if(userAnswer == quizVector[i].getAnswer()){
            cout << "Correct!";
            quizVector[i].updateScore(1);
            cout << "Current Score: " << quizVector[i].getScore() << endl << endl;
        }else if(userAnswer != quizVector[i].getAnswer()){
            cout << "Wrong Answer! Correct Answer: " << quizVector[i].getAnswer() << endl;
            quizVector[i].updateScore(-1);
            cout << "Current Score: " << quizVector[i].getScore() << endl << endl;
        }
    }
    
    cout << "Number of Questions: " << quizVector.size() - 1 << endl;
    
    // allows random shuffle 
    //Show the question
    //Collect the input
    //Display the results
    
    cout << "Closing file!" << endl;
    fp.close();
    return 0;
}

/*
if lastchar of string == 
*/