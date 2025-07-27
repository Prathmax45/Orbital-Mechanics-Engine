#ifndef VECTOR_3D_H
#define VECTOR_3D_H

class vector_3D
{
    public:
    
    double x,y,z;

    vector_3D();

    vector_3D(double x_ , double y_ , double z_);

    vector_3D operator+(const vector_3D& other) const;
    vector_3D operator-(const vector_3D& other) const;
    vector_3D operator*( double i) const;
    vector_3D operator/(const vector_3D& other)const;
    vector_3D div(double other)const;
 

    double dot(const vector_3D& other)const;
    vector_3D cross(const vector_3D& other)const;

    double length()const ;
    vector_3D normalize() const ;

    

    void display();

    
};







#endif