/************************************************************
* @file FibLFSR.h
* @author: Chris Olah
* @copyright Umass Lowell February 7 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 1B
* Professor: Dr. Daly
************************************************************/
#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::ostream;

/**
* @brief Class to describe FibLFSR object 
* @since 1.0 
*/
class FibLFSR { //< Class structure for FibLFSR object
    public:
        FibLFSR(string seed); //< Constructor to create LFSR with initial seed

        
        int step(); //< Simulate one step and return new bit as 0 or 1           

        
        int generate(int k); //< Simulate k steps and return k-bit integer   

        
        friend ostream& operator<< (ostream& os, const FibLFSR& flfsr); //< Overloading the << operator to display its current register value in printable form

    private:
        string _seed; //< String to store seed
        

        int _tap1 = 0;
        int _tap2 = 2;
        int _tap3 = 3;
        int _tap4 = 5; //< Seed tap positions
};