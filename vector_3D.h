#ifndef VECTOR_3D_H
#define VECTOR_3D_H

class vector_3D
{
    public:
    
    double x,y,z;

    vector_3D();

    vector_3D(double x_ , double y_ , double z_);

    vector_3D operator+(vector_3D& other);
    vector_3D operator-(vector_3D& other);
    vector_3D operator*(double i);
    vector_3D operator/(vector_3D& other);
 

    double dot(vector_3D& other);
    vector_3D cross(vector_3D& other);

    double length();
    vector_3D normalize();

    

    void display();

    
};







#endif