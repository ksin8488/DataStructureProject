//
//  FileController.cpp
//  DataStructureProject
//
//  Created by Singh, Kashish on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "FileController.hpp"

vector<CrimeData> FileController :: readCrimeDataToVector(string filename)
{
    std :: vector<CrimeData> crimeVector;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    //If the file exists at that path...
    if (dataFile.is_open())
    {
        //Keep reading until you are at the end of the file.
        while(!dataFile.eof())  //eof - "end of file"
        {
            //Grab each line from the CSV seperated by the carriage return character.
            getline(dataFile, currentCSVLine, '\n');    //consumes/eats the file
            //Exclude header row
            if(rowCount != 0)
            {
                //Create a CrimeData instance from the line.
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimeVector.push_back(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return crimeVector;
}
