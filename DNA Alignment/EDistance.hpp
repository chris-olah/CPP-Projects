// Copyright 2022 Chris Olah

#ifndef _HOME_CHRIS_OLAH_PS5_EDISTANCE_HPP_
#define _HOME_CHRIS_OLAH_PS5_EDISTANCE_HPP_

#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class EditDistance{
        public:
               void alg();

               ~EditDistance();

               EditDistance(std::string input1, std::string input2);

               void print();

               static int penalty(char a, char b); // returns the penalty for aligning
               // chars a and b (this will be a 0 or a 1)

               static int min(int a, int b, int c); //NOLINT
               // returns min of three arguments

               int OptDistance(); // which populates the matrix based on having the two
                                             // strings, and returns the optimal distance
                                             // (from the [0][0] cell of the matrix when done).

               std::string Alignment(); // which traces the matrix and
                                                      // returns a string that can be
                                                      // printed to display the actual alignment.
                                                      // In general, this will
                                                      // be a multi-line string

        private:
               int rowCount;
               int colCount;
               int** dnarray;
               std::string dna1;
               std::string dna2;
};

#endif // _HOME_CHRIS_OLAH_PS5_EDISTANCE_HPP_
