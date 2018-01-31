//
//  Controller.cpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Look code on the screen" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    
    codeTimer.startTimer();
    for(int index = 0; index < 500; index++)
    {
        cout << "Index is " << index << "\t";   // \t is the tab operator
    }
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}

