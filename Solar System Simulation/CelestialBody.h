/************************************************************
* @file CelestialBody.h
* @author: Chris Olah
* @copyright Umass Lowell February 22 2022
* @version 1.0
* Course: Computing IV (COMP.2040)
* Assignment: Project 2B
* Professor: Dr. Daly
************************************************************/

#ifndef CelestialBody_H
#define CelestialBody_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
const int height = 512;
const int width = 512;

class CelestialBody:public sf::Drawable
{
    public:

    CelestialBody();//default
    CelestialBody(double xposition, double yposition, double xvelocity, double yvelocity, double mass, string filename); // Constructor
    friend istream& operator>> (istream &input, CelestialBody &b);//overloaded
    void radius (float radius);
    void position();

    void forces (double xForce, double yForce);//used
    void step (double time);

    double get_mass()
    {
        return _mass;
    }

    double get_x()
    {
        return _xposition;
    }

    double get_y()
    {
        return _yposition;
    }

    private:

    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    double _xposition, _yposition;
    double _xvelocity, _yvelocity;
    double _mass;
    double _radius;
    string _filename;


    double acceleration_x;
    double acceleration_y;

    double force_x;
    double force_y;

    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
    
};

class Universe {
    public:
        vector<shared_ptr<CelestialBody> >body;
        double calc_force_x (CelestialBody &first, CelestialBody &second);
        double calc_force_y (CelestialBody &first, CelestialBody &second);
    
    private:
        double seconds;
        double net_force;
};

#endif
