#ifndef BODY_H
#define BODY_H
#include <iostream>
#include "vector_3D.h"

using namespace std;


class body
{
    double mass;
    vector_3D velocity;
    vector_3D acceleration;
    string body_name;
    
    body();
    
    body(double m, vector_3D vel , vector_3D acc , string name);

    void display();
    void reset_acceleration();

    friend ostream& operator<<(ostream& os , vector_3D& other);
    

    
    




};















#endif