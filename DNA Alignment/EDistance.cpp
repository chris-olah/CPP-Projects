// Copyright 2022 Chris Olah

#include "EDistance.hpp"

EditDistance::EditDistance(std::string input1, std::string input2) {
          dna1 = input1;
          dna1.push_back(’-’);

          dna2 = input2;
        dna2.push_back(’-’);

        rowCount = input1.length() + 1;
        colCount = input2.length() + 1;

        dnarray = new int * [rowCount];
        for (int i = 0; i < rowCount; i++)
               dnarray[i] = new int[colCount];

        for (int i = 0; i < rowCount; i++) {
               for (int j = 0; j < colCount; j++) {
                      dnarray[i][j] = 0;
               }
        }
        // setting values begining with power of two
        int exp = 0;
        for (int i = colCount - 1; i >= 0; i--) {
               dnarray[rowCount-1][i] = 2 * exp;
               exp++;
        }

        int exp1 = 0;
        for (int i = rowCount - 1; i >= 0; i--) {
               dnarray[i][colCount-1] = 2 * exp1;
               exp1++;
        }
}

int EditDistance::penalty(char a, char b) {
        if (a == b) {
               return 0;
        } else {
               return 1;
        }
}

int EditDistance:: min(int a, int b, int c) {
        a = a + 2;
        b = b + 2;
        int min = 0;
        if (a <= b && a <= c) {
               min = a;
        } else if (b <= a && b <= c) {
               min = b;
        } else if (c <= b && c <= a) {
               min = c;
        }

        return min;
}

void EditDistance::alg() {
        int val;
        int compare;

        for (int j = colCount - 2; j >= 0; j--) {
               for (int i = rowCount- 2; i >= 0; i--) {
                      compare = penalty(dna1.at(i), dna2.at(j));

                      val = min(dnarray[i+1][j], dnarray[i][j+1], dnarray[i+1][j+1] + compare);

                      dnarray[i][j] = val;
               }
        }
}

// returning edit distance using lambda expression
int EditDistance::OptDistance() {
        int dist = dnarray[0][0];
        auto f = [dist]{return dist;};
        auto j = f();
        return j;
}

std::string EditDistance::Alignment() {
        int count;
        int i = 0;
        int j = 0;
        int distance = dnarray[0][0];
        int checker = 0;
        std::string alignment;
        while (checker != distance) {
               if (dnarray[i][j] == dnarray[i+1][j+1]+penalty\
                      (dna1.at(i), dna2.at(j))) { // DIAGONAL
                      count = dnarray[i][j]-dnarray[i+1][j+1];

                      alignment.push_back(dna1.at(i));
                      alignment.push_back(dna2.at(j));
                       alignment.push_back(count+’0’);
                      checker = checker + count;
                      alignment.push_back(’\n’);
                      if (checker != distance) {
                             i++;
                             j++;
                      } else {
                              return alignment;
                      }
               }

               if (dnarray[i][j] == dnarray[i][j+1]+2) { // Right
                      count = dnarray[i][j]-dnarray[i][j+1];
                      alignment.push_back(’-’);
                      alignment.push_back(dna2.at(j));
                      alignment.push_back(count+’0’);
                      alignment.push_back(’\n’);
                      checker = checker+count;
                       if (checker != distance) {
                              i = i + 0;
                              j++;
                       } else {
                               return alignment;
                        }
               }

               if (dnarray[i][j] == (dnarray[i+1][j])+2) { // Down
                      count = dnarray[i][j]-dnarray[i+1][j];
                      alignment.push_back(dna1.at(i));
                      alignment.push_back(’-’);
                      alignment.push_back(count+’0’);
                      alignment.push_back(’\n’);
                      checker = checker + count;
                      if (checker != distance) {
                             i++;
                             j = j + 0;
                      } else {
                             return alignment;
                      }
               }
        }
        return alignment;
}

void EditDistance::print() {
        for (int i = 0; i < colCount; i++) {
               std::cout << std::setw(6) << i;
        }

        std::cout << std::endl << std::endl;

        for (int i = 0; i < rowCount; i++) {
               std::cout << i << ":";
               for (int j = 0; j < colCount; j++) {
                      std::cout << std::setw(6) << dnarray[i][j];
               }
               std::cout << std::endl;
        }
}

EditDistance::˜EditDistance() {
        for (int i = 0; i < rowCount; i++) {
               delete[] dnarray[i];
        }
        delete[] dnarray;
}