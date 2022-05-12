/************************************************************
* @file TFractal.h
* @author: Chris Olah
* @copyright Umass Lowell February 28 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 3
* Professor: Dr. Daly
************************************************************/
#ifndef _HOME_CHRIS_OLAH_PS3_TFRACTAL_H_
#define _HOME_CHRIS_OLAH_PS3_TFRACTAL_H_

#include "Triangle.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void fTree(sf::RenderTarget& target, int recursionDepth, const Triangle& parent);   // NOLINT
void fTree(sf::RenderTarget& target, double triLength, int recursionDepth, int windowSize);   // NOLINT

#endif  // _HOME_CHRIS_OLAH_PS3_TFRACTAL_H_
