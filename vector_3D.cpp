#include <iostream>
#include "vector_3D.h"
using namespace std;

vector_3D :: vector_3D() : x(0.0) , y(0.0) , z(0.0){}
vector_3D :: vector_3D(double x_ , double y_ , double z_)
{
    x = x_;
    y = y_;
    z = z_;
}

vector_3D vector_3D::operator+(vector_3D& other)
{
    vector_3D v;
    v.x = this->x + other.x;
    v.y = this->y + other.y;
    v.z = this->z + other.z;
    return v;
}

vector_3D vector_3D::operator-(vector_3D& other)
{
    vector_3D v;
    v.x = this->x - other.x;
    v.y = this->y - other.y;
    v.z = this->z - other.z;
    return v;
}

vector_3D vector_3D :: operator*(double i)
{
    vector_3D temp;
    temp.x = this->x * i;
    temp.y = this->y * i;
    temp.z = this->z * i;
    return temp;
    
}


vector_3D vector_3D::operator/(vector_3D& other)
{
    vector_3D v;
    v.x = this->x / other.x;
    v.y = this->y / other.y;
    v.z = this->z / other.z;
    return v;
}


double vector_3D:: dot(vector_3D& other)
{
    vector_3D v;
    v.x = this->x * other.x;
    v.y = this->y * other.y;
    v.z = this->z * other.z;
    return v.x + v.y + v.z;
}


void vector_3D :: display()
{
    cout << "x co-ordinate = " << x << endl;
    cout << "y co-ordinate = " << y << endl;
    cout << "z co-ordinate = " << z <<endl;

}