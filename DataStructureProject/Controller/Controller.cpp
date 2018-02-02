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
    
    findMaxAndMin();
    
    testArray();
}

void Controller :: findMaxAndMin()
{
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ksin8488/SwiftProjectsPM/DataStructureProject/DataStructureProject/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for(int index = 1; index < myData.size(); index++)
    {
        if(myData[minIndex] > myData[index])    //linear data comparison for finding the min
        {
            minIndex = index;
        }
        else if(myData[maxIndex] < myData[index])
        {
            maxIndex = index;
        }
    }
    searchTimer.stopTimer();
    cout << "The smalles Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
}

void Controller :: testArray()
{
    Array<int> kashishArray(45);
    
    kashishArray[0] = 123;
    kashishArray.setAtIndex(0, 321);
    
    cout << kashishArray[0] << endl;
}

