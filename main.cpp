#include <iostream>
#include <vector>
#include <fstream>
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
    string question;
    vector<string> questionType;
    
    fp.open(argv[1]);
    if(!fp.is_open()){
        cout << "File: " << argv[1] << " could not be opened" << endl;
    }
    cout << "File was opened" << endl;
/*  while(!fp.eof()){
    }
*/
    getline(fp,question);
    cout << "Question 1: " << question << endl;

    cout << "Closing file" << endl;
    fp.close();
    return 0;
}