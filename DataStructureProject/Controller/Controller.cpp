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
   
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ksin8488/SwiftProjectsPM/DataStructureProject/DataStructureProject/Data/crime.csv"); //"" contains Absolute file path
    
    for(int i = 200; i <= 215; i++)
    {
        cout << i << " is " << myData[i] << endl;
    }
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    
    
}

