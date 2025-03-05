#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "buildResultString.h"
#include "QA.h"

using namespace std;

int main(int argc, char *argv[]){

/*    QA Test; // Testing update score function
    cout << "Testing QA update score" << endl;
    Test.updateScore(-1);
    cout << "Score: " << Test.getScore() << endl;
*/
    ifstream fp; 
    int score; 
    string question;
    string answer;
    vector<QA> quizVector;
    
    fp.open(argv[1]);
    if(!fp.is_open()){
        cout << "File: " << argv[1] << " could not be opened" << endl;
    }
    cout << "File was opened" << endl << endl;

    while(!fp.eof()){ // Reads in the contents of the database.txt file
        getline(fp, question);
        getline(fp, answer);
        QA quiz(question,answer);
        quizVector.push_back(quiz);
    }
    for(int i = 0; i < quizVector.size(); i++){
        cout << quizVector[i] << endl;
    }

    cout << "Closing file" << endl;
    fp.close();
    return 0;
}