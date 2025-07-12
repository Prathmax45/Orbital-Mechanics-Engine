#include <iostream>
#include <fstream>
#include "vector_3D.h"
#include "body.h"
#include "simulator.h"

using namespace std;

simulator :: simulator() :  G(6.67430e-11), timestep(60),stepcount(0){}

void simulator :: addBody(body other)
{
    bodies.push_back(other);

}

void simulator :: calculate_forces()
{
    for (int i = 0 ; i < bodies.size(); i++)
    {
        for (int j = i+1 ; j < bodies.size();j++)
        {
            body& a = bodies[i];
            body& b = bodies[j];

            vector_3D r = b.position - a.position;
            double distance = r.length();
            vector_3D force_dir = r.div(distance);
            double force_mag = G * a.mass * b.mass / (distance * distance);

            vector_3D force = force_dir * force_mag;

            a.acceleration = a.acceleration + (force.div(a.mass));
            b.acceleration = b.acceleration + (force.div(b.mass));

        }
    }
}
void simulator :: update_bodies()
{
    for(body& b : bodies)
    {
        b.velocity = b.velocity +(b.acceleration * timestep);
        b.position = b.position +(b.velocity * timestep);
    }
}

void simulator :: simulate_steps()
{
    for (body& b : bodies)
        b.reset_acceleration();

    calculate_forces();
    update_bodies();
    stepcount++;

}

void simulator :: simulate(int steps)
{
    ofstream log("stimulation_log.txt");

    for (int i = 0 ; i < steps ; i++)
    {
            simulate_steps();
            for(body& b : bodies)
                b.body_display(log);
            
            log <<"step count = " << stepcount << "  |  Time passed = " << stepcount * timestep / 86400 << " days" << endl;
            log << "--------------------------------------------------------------------------------------------------------" <<endl;
            
          
    }
    log.close();
}

