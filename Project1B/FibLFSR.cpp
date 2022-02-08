/************************************************************
* @file FibLFSR.cpp
* @author: Chris Olah
* @copyright Umass Lowell February 7 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 1B
* Professor: Dr. Daly
************************************************************/

#include "FibLFSR.h"
#include <iostream> 
#include <string>

/**
* @brief FibLFSR constructor definition for initial seed
* @param seed value of seed 
* @since 1.0 
*/
FibLFSR::FibLFSR(string seed) { //< FibLFSR constructor definition for initial seed
    _seed = seed;
}

/**
* @brief Simulate one step and calculate new extracted bit 
* @return Extracted bit calculated from xor of tap positions (0 or 1)
* @since 1.0 
*/  
int FibLFSR::step() { //< FibLFSR step function definition
    char tapPosition1 = _seed[_tap1];
    char tapPosition2 = _seed[_tap2];
    char tapPosition3 = _seed[_tap3];
    char tapPosition4 = _seed[_tap4];

    int newBit = (((tapPosition1 ^ tapPosition2) ^ tapPosition3) ^ tapPosition4); //< Calculated new bit given the tap positions 

    int seedLength = _seed.size(); //< Get seed length 
    
    for (int i = 0; i < (seedLength) - 1; i++) { //< Shift bits to left
           _seed[i] = _seed[i + 1];
    }

    _seed.back() = newBit; //< Assign last bit to end of seed (after shift to left)
 
    return _seed.back(); //< Return new bit value
}

/**
* @brief FibLFSR constructor definition for initial seed
* @param k value of how many steps (step()) to complete
* @return k-bit integer after k steps generated 
* @since 1.0 
*/
int FibLFSR::generate(int k) { //< FibLFSR generate function definition
    int extractedBit = 0; //< Declare/initialize extract bit 

    for(int i = 0; i < k; i++) {
        extractedBit = extractedBit * 2 + step();
    }
    
    return extractedBit;
}

/**
* @brief Overloading the << operator to display its current register value in printable form
* @param os ostream to output LFSR 
* @param flfsr pass flfsr object to output 
* @return output of current register value 
* @since 1.0 
*/
ostream& operator<<(ostream& os, const FibLFSR& flfsr) { //< FibLFSR overload insertion operator definition
    os << flfsr._seed;

    return os; 
}




