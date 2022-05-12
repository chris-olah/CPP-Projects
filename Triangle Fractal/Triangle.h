/************************************************************
* @file Triangle.h
* @author: Chris Olah
* @copyright Umass Lowell February 28 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 3 Triangle Fractal
* Professor: Dr. Daly
************************************************************/

#ifndef _HOME_CHRIS_OLAH_PS3_TRIANGLE_H_
#define _HOME_CHRIS_OLAH_PS3_TRIANGLE_H_

#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable {
 public:
          explicit Triangle(double sideLength);
          Triangle(double sideLength, int windowSize);
          Triangle(const Triangle &t);
          double getLength() {
               return length;
          }
          sf::Vector2f getPosition(void);
          void setColor(const Triangle &t);
          void setPosition(sf::Vector2f initialPos);
          void reposition(int childNum, double length);
 private:
          double length;
          sf::ConvexShape tri;
          virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{ //NOLINT function won't work if target is const
               target.draw(tri, states);
          }
};
#endif  // _HOME_CHRIS_OLAH_PS3_TRIANGLE_H_
