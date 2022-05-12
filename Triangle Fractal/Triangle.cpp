/************************************************************
* @file Triangle.cpp
* @author: Chris Olah
* @copyright Umass Lowell February 28 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 3 Triangle Fractal
* Professor: Dr. Daly
************************************************************/

#include "Triangle.h"
#include <random>

Triangle::Triangle(double sideLength, int windowSize) {
     tri.setPointCount(3);
     tri.setPoint(0, sf::Vector2f(0, 0));
     tri.setPoint(1, sf::Vector2f(sideLength/2, (sideLength/2) * sqrt(3)));
     tri.setPoint(2, sf::Vector2f(sideLength, 0));

     tri.setOutlineThickness(1);
     if (sideLength > 60)
          tri.setOutlineColor(sf::Color::Green);
     else 
          tri.setOutlineColor(sf::Color::Blue);
     tri.setFillColor(sf::Color::Transparent);
     tri.setPosition(windowSize/5, windowSize/3);

     length = sideLength;
}

Triangle::Triangle(const Triangle &t) {
     tri = t.tri;
}

Triangle::Triangle(double sideLength) {
     tri.setPointCount(3);
     tri.setPoint(0, sf::Vector2f(0, 0));
     tri.setPoint(1, sf::Vector2f(sideLength/2, (sideLength/2) * sqrt(3)));
     tri.setPoint(2, sf::Vector2f(sideLength, 0));

     tri.setOutlineThickness(1);
     tri.setOutlineColor(sf::Color::Blue);
     tri.setFillColor(sf::Color::Transparent);

     length = sideLength;
}

sf::Vector2f Triangle::getPosition(void) {
     return tri.getPosition();
}

void Triangle::setPosition(sf::Vector2f initialPos) {
     tri.setPosition(initialPos);
     return;
}

void Triangle::setColor(const Triangle &t) {
     tri.setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Triangle::reposition(int childNum, double length) {
     switch (childNum) {
             case 1:
                  tri.move(-length/2, -(length/2 * sqrt(3)));
                  break;
             case 2:
                  tri.move(length*2, 0);
                  break;
             case 3:
                  tri.move(0, length * sqrt(3));
                  break;
    }
}
