/************************************************************
Author: Chris Olah
Course: Computing IV (COMP.2040)
Assignment: Project 1A
Professor: Dr. Daly
Date: February 1 2022
************************************************************/

#include "FibLFSR.h"
#include <iostream> 
#include <string>

// FibLFSR constructor definition for initial seed
FibLFSR::FibLFSR(string seed) {
    _seed = seed;
}

// FibLFSR step function definition
int FibLFSR::step() {
    char tapPosition1 = _seed[_tap1];
    char tapPosition2 = _seed[_tap2];
    char tapPosition3 = _seed[_tap3];
    char tapPosition4 = _seed[_tap4];

    // Calculated new bit given the tap positions 
    int newBit = (((tapPosition1 ^ tapPosition2) ^ tapPosition3) ^ tapPosition4);

    int seedLength = _seed.size();

    // Shift bits to left
    for (int i = 0; i < (seedLength) - 1; i++) {
           _seed[i] = _seed[i + 1];
    }

    // Assign last bit to end of seed (after shift to left)
    _seed.back() = newBit;
 
    // Return new bit value
    return _seed.back();
}

// FibLFSR generate function definition
int FibLFSR::generate(int k) {
    int extractedBit = 0;

    for(int i = 0; i < k; i++) {
        extractedBit = extractedBit * 2 + step();
    }
    
    // return extracted generated bit after k steps
    return extractedBit;
}

// FibLFSR overload insertion operator definition
ostream& operator<<(ostream& os, const FibLFSR& flfsr) {
    //output seed string to os
    os << flfsr._seed;

    return os; 
}




