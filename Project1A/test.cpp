/************************************************************
Author: Chris Olah
Course: Computing IV (COMP.2040)
Assignment: Project 1A
Professor: Dr. Daly
Date: February 1 2022
CODE EXTENDED FROM Dr. Rykalova (Updated 1/31/2020)
************************************************************/
#include <iostream>
#include <string>
#include <sstream>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// Given test cases for testing 16 bit seed
BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

// Tests 10 bit seed with all 0's
BOOST_AUTO_TEST_CASE(twentyBitsZeroes) {

  FibLFSR l("00000000000000000000");

  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);

  FibLFSR l2("00000000000000000000");
  BOOST_REQUIRE(l2.generate(9) == 0);

}

// Tests to make sure constructor stores seed correctly
// Also tests overloading << insertion operator
BOOST_AUTO_TEST_CASE(fiveBitsTapAtZero) {
  FibLFSR l("0000000111111111001010101011");
  std::stringstream buffer;
  buffer << l;

  BOOST_REQUIRE(buffer.str().compare("0000000111111111001010101011") == 0);

  FibLFSR l2("011011");
  buffer.str("");
  buffer.clear();
  buffer << l2;

  BOOST_REQUIRE(buffer.str().compare("011011") == 0);
}


