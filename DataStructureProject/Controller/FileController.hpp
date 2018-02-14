//
//  FileController.hpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Data/CrimeData.hpp"    //the ../ tells the command line to go UP to the previous folder and THEN into the data folder
#include <string>
#include <fstream>      //how we deal with files
#include <iostream>     //dealing with inputs and outputs
#include <vector>
#include <sstream>      //deals with strings as a stream
#include "LinkedList.hpp"

using namespace std;

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);    //static method doesn't need an instance
    static LinkedList<CrimeData> readDataToList(string filename);

};

#endif /* FileController_hpp */
