#ifndef BODY_H
#define BODY_H
#include <iostream>
#include <fstream>
#include "vector_3D.h"

using namespace std;


class body
{
    public:
    double mass;
    vector_3D position;
    vector_3D velocity;
    vector_3D acceleration;
    string body_name;
    double KE;
    double PE;
    
    body();
    
    body(double m,vector_3D pos,vector_3D vel , string name);

    void body_display(ofstream &out);
    void reset_acceleration();

    friend ostream& operator<<(ostream& os ,const vector_3D& other);
    

    
    




};















#endif