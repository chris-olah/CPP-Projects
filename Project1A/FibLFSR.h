/************************************************************
Author: Chris Olah
Course: Computing IV (COMP.2040)
Assignment: Project 1A
Professor: Dr. Daly
Date: February 1 2022
************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::ostream;

// Class structure for FibLFSR object
class FibLFSR {
    public:
        // Constructor to create LFSR with initial seed
        FibLFSR(string seed);

        // Simulate one step and return new bit as 0 or 1
        int step();             

        // Simulate k steps and return k-bit integer
        int generate(int k);    

        // Overloading the << operator to display its current register value in printable form
        friend ostream& operator<< (ostream& os, const FibLFSR& flfsr);

    private:
        // String to store seed
        string _seed;
        
        // Seed tap positions
        int _tap1 = 0;
        int _tap2 = 2;
        int _tap3 = 3;
        int _tap4 = 5;
};