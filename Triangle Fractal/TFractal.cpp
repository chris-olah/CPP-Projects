/************************************************************
* @file TFractal.cpp
* @author: Chris Olah
* @copyright Umass Lowell February 28 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 3 Triangle Fractal
* Professor: Dr. Daly
************************************************************/

#include "TFractal.h"
#include "Triangle.h"

int main(int argc, char* argv[]) {
     double L = atof(argv[1]);
     int N = atoi(argv[2]);  //< Take command line arguments
     int windowSize = L * 3;  //< Set window size
     Triangle myTriangle(L, windowSize);

     sf::Font font;
     if (!font.loadFromFile("Georgia.ttf"))
          return -1;
     sf::Text text;
     text.setFont(font);
     text.setString("Base Triangle Size: " + std::to_string(L) \
     + "          Recursion Depth: " + std::to_string(N));
     text.setCharacterSize(18);

     sf::RenderWindow window1(sf::VideoMode(L * 3, L *3), "Triangle Fractal");
     while (window1.isOpen()) {
          sf::Event event;
          while (window1.pollEvent(event)) {
               if (event.type == sf::Event::Closed)
                    window1.close();
          }
          window1.clear(sf::Color::White);
          fTree(window1, L, N, windowSize);  //< call fTree window function
          window1.draw(text);
          window1.display();
     }
     return 0;
}


void fTree(sf::RenderTarget& target, int N, Triangle& parent) {  // NOLINT
     if (N < 1) {
          return;
     }

     target.draw(parent);  //< Draw base triangle

     double newLength = (parent.getLength() / 2);  //< Store new triangle length

     Triangle child1(newLength);
     Triangle child2(newLength);
     Triangle child3(newLength);  //< Create new child triangles

     child1.setPosition(parent.getPosition());
     child2.setPosition(parent.getPosition());
     child3.setPosition(parent.getPosition());

     child1.reposition(1, newLength);
     child2.reposition(2, newLength);
     child3.reposition(3, newLength);

     fTree(target, N - 1, child1);
     fTree(target, N - 1, child2);
     fTree(target, N - 1, child3);
}

void fTree(sf::RenderTarget& target, double length, int N, int windowSize) {  //NOLINT
     Triangle myTriangle(length, windowSize);
     fTree(target, N, myTriangle);
}

