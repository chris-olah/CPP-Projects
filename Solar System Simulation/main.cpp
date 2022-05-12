/************************************************************
* @file main.cpp
* @author: Chris Olah
* @copyright Umass Lowell February 22 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 2B
* Professor: Dr. Daly
************************************************************/

#include "CelestialBody.h"
using namespace std;

int main(int argc, char* argv[])
{   
    sf::RenderWindow window(sf::VideoMode(512,512),"Celestial Bodies");
    Universe universe;

    double universe_time = atof (argv[1]); //get values from command line
    double step_time = atof ( argv[2]);
    double simulation = 0;
  
    int numofPlanets;
    cin >> numofPlanets;

    double radiusofUni;
    cin >> radiusofUni;

    vector <CelestialBody> trial;

    for(int i = 0; i < numofPlanets; i++) //get planets
    {
        shared_ptr<CelestialBody>planet(new CelestialBody);
        cin >> *planet;
        planet->radius(radiusofUni);
        planet->position();
        trial.push_back(*planet);
        universe.body.push_back(planet);
    } 
    
    sf::Music music;//play background music
    if(!music.openFromFile("2001.wav"))
    {
        return -1;
    }
    music.play();
    

    sf::Font time_font; //set font
    time_font.loadFromFile("Georgia Italic.ttf");

    sf::Text text;
    text.setFont(time_font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Yellow);

    sf::Texture background; // set the background
    background.loadFromFile("starfield.jpg");

    sf::Sprite spritex;
    spritex.setTexture(background);

    vector<CelestialBody>::iterator it;
    vector<CelestialBody>::iterator x, y;


    while(window.isOpen())
    {
        sf:: Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
            window.close();
            }
        }

        window.clear();
        window.draw(spritex);

        text.setString("Time: " + to_string(simulation));
        window.draw(text);

    double fx, fy;
    x = trial.begin();
    
    for(int i = 0; i < numofPlanets; i++)
    {
      y = trial.begin();
      fx = 0;
      fy = 0;

      for(int j = 0; j < numofPlanets; j++)
	    {
	        if(i != j)
	        {
	            fx += universe.calc_force_x(*x,*y);
	            fy += universe.calc_force_y(*x,*y);
	        }
	        y++;
	    }
      
      x->forces(fx,fy);
      x++;
    }

    for(it = trial.begin(); it != trial.end(); it++)
      {
    	window.draw(*it);
	    it->step(step_time);
	    it->position();
      }
   
    window.display();
    simulation++;
    if(simulation >= universe_time)
    {
        cout << "hello";
    }
 }
    return 0;
}

