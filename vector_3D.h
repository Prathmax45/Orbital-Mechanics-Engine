#ifndef VECTOR_3D_H
#define VECTOR_3D_H

class vector_3D
{
    double x,y,z;

    public:
    vector_3D();

    vector_3D(double x_ , double y_ , double z_);

    vector_3D operator+(vector_3D& other);
    vector_3D operator-(vector_3D& other);
    vector_3D operator*(double i);
    vector_3D operator/(vector_3D& other);
 

    double dot(vector_3D& other);

    void display();

    
};







#endif