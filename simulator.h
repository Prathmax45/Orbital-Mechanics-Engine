#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "vector_3D.h"
#include <vector>
#include "body.h"

class simulator
{
    public:
    vector<body> bodies;
    double G;
    double timestep;
    double stepcount;

    
    simulator();

    void addBody(body other);
    void calculate_forces();
    void update_bodies();
    void simulate_steps();
    void simulate(double steps);
   


};




















#endif  