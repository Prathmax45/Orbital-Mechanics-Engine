#include <iostream>
#include "vector_3D.h"
#include "body.h"
using namespace std;

body :: body() : mass(1000.0) , velocity(10.0,10.0,10.0) ,position(0.0,0.0,0.0) , body_name("untitled"),KE(0.0),PE(0.0) {}

body :: body(double m,vector_3D pos, vector_3D vel  , string name)
{
    mass = m;
    position = pos;
    velocity = vel;
    body_name = name;
    KE = 0.0;
    PE = 0.0;
}

ostream& operator << (ostream& os , const vector_3D& other)
{
    os << "(" << other.x<<","<<other.y <<","<<other.z<<")";
    return os;
}

void body :: reset_acceleration ()
{
    this->acceleration.x = 0.0;
    this->acceleration.y = 0.0;
    this->acceleration.z = 0.0;
}

void body :: body_display(ofstream &out)
{
    out << "Object                = " << body_name << endl;
    out << "Mass                  = " << mass << endl;
    out << "Position co-ordinates = " << position << endl;
    out << "Velocity              = " << velocity << endl;
    out << "Acceleration          = " << acceleration << endl;
}




























