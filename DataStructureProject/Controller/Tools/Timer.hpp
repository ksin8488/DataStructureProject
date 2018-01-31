//
//  Timer.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>
#include <assert.h>
#include <iostream>

class Timer
{
public:
    Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayInformation();
    long getTimeInMicroseconds();
private:
    clock_t executionTime;  //clock_t tracks the actual time that occurs when the timer is running
};

#endif /* Timer_hpp */
