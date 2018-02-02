//
//  Controller.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <vector>
#include "Tools/Timer.hpp"  //Need to give the file directory
#include "FileController.hpp"

class Controller
{
public:
    void start();
private:
    void findMaxAndMin();
};

#endif /* Controller_hpp */
