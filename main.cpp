#include <iostream>
#include <fstream>
#include "buildResultString.h"
#include "QA.h"

using namespace std;
int main(int argc, char *argv[]){

    QA Test;
    cout << "Testing QA update score" << endl;
    Test.updateScore(-1);
    cout << "Score: " << Test.getScore() << endl;


    return 0;
}