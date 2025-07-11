#include <iostream>
#include "vector_3D.h"
#include "body.h"
using namespace std;

body :: body() : mass(1000.0) , velocity(10,10,10) , acceleration(1,1,1) , body_name("untitled") {}

body :: body(double m, vector_3D vel , vector_3D acc , string name)
{
    mass = m;
    velocity = vel;
    acceleration = acc;
    body_name = name;    
}

ostream& operator << (ostream& os , vector_3D& other)
{
    os << "(" << other.x<<","<<other.y <<","<<other.z<<")";
    return os;
}

void body :: reset_acceleration ()
{
    this->acceleration.x = 0;
    this->acceleration.y = 0;
    this->acceleration.z = 0;
}

void body :: display()
{
    cout << "Object Name = " << body_name << endl;
    cout << "mass = " << mass << endl;
    cout << "velocity = " << velocity << endl;
    cout << "Acceleration = " << acceleration << endl;
}




























