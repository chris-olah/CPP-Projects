#include "CelestialBody.h"

CelestialBody::CelestialBody() {
  return;
}

CelestialBody::CelestialBody(double xposition, double yposition, double xvelocity, double yvelocity, double mass,string filename) {
  _xposition = xposition;
  _yposition = yposition;
  _xvelocity = xvelocity;
  _yvelocity = yvelocity;
  _mass = mass;
  _filename = filename;
  texture.loadFromImage(image);
  sprite.setTexture(texture);
  sprite.setPosition(sf::Vector2f(_xposition, _yposition));
}

istream& operator>> (istream &input, CelestialBody &b) {
  input >> b._xposition >> b._yposition;
  input >> b._yvelocity >> b._yvelocity;
  input >> b._mass >> b._filename;

  b.texture.loadFromFile(b._filename);
  b.sprite.setTexture(b.texture);
  b.sprite.setPosition(sf::Vector2f(b._xposition, b._yposition)); //intial

  b.acceleration_x = 0;
  b.acceleration_y = 0;

  b.force_x = 0;
  b.force_y = 0;

  return input;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(sprite);
}


void CelestialBody::radius(float radius)
{
    _radius = radius;
}

void CelestialBody::forces(double xForce, double yForce)
{
  force_x = xForce;
  force_y = yForce;
}


void CelestialBody::position()//done
{ 
  double newxposition = ((_xposition / _radius) * (width / 2)) + (height / 2);                      
  double newyposition = ((_yposition / _radius) * (width / 2)) + (height / 2);                     

  sprite.setPosition(sf::Vector2f(newyposition, newxposition));
}

double Universe::calc_force_x(CelestialBody& first, CelestialBody& second)
{
 const double G = 6.67e-11;
 double delta_x = second.get_x() - first.get_x();
 double delta_y = second.get_y() - first.get_y();
 double r = pow(delta_x,2) + pow (delta_y, 2);
 double sqrtr = sqrt(r);

 double f = ( G * first.get_mass() * second.get_mass()) / r;
 double F = f* (delta_x /sqrtr);

 return F;

}

double Universe::calc_force_y(CelestialBody& first, CelestialBody& second)
{
 const double G = 6.67e-11;

 double delta_x = second.get_x() - first.get_x();
 double delta_y = second.get_y() - first.get_y();
 double r = pow(delta_x,2) + pow (delta_y, 2);
 double sqrtr = sqrt(r);

 double f = ( G * first.get_mass() * second.get_mass()) / r;
 double F = f* (delta_y /sqrtr);

 return F;
 
}

void CelestialBody::step(double t)
{

  acceleration_x = force_x / _mass;
  acceleration_y = force_y / _mass;

  _xvelocity = _xvelocity + (acceleration_x * t);
  _yvelocity = _yvelocity + (acceleration_y * t);

  _xposition = _xposition + ( _xvelocity * t);
  _yposition = _yposition + ( _yvelocity * t);

}






