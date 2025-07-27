#include <iostream>
#include <fstream>
#include "vector_3D.h"
#include "body.h"
#include "simulator.h"

using namespace std;

simulator :: simulator() :  G(6.67430e-11), timestep(10.0),stepcount(0.0){}

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
            double distance = r.length() + 1e-10;
            vector_3D force_dir = r.div(distance);
            double force_mag = G * a.mass * b.mass / (distance * distance);

            vector_3D force = force_dir * force_mag;

            a.acceleration = a.acceleration + (force.div(a.mass));
            b.acceleration = b.acceleration - (force.div(b.mass)); // newtons third law

        }
    }
}
void simulator :: update_bodies()
{
    for(body& b : bodies)
    {
        b.velocity = b.velocity +( b.acceleration * timestep * 0.5);
        b.KE =(0.5 * b.mass * (b.velocity.dot(b.velocity)));
        b.position = b.position +(b.velocity * timestep);
        

    }
    for (body& b : bodies)
        b.reset_acceleration();
    
    calculate_forces();

    for (body& b : bodies)
    {
        b.velocity = b.velocity +( b.acceleration * timestep * 0.5);
        b.KE =(0.5 * b.mass * (b.velocity.dot(b.velocity)));
        b.position = b.position +(b.velocity * timestep);
    }
    for (int i = 0 ; i < bodies.size() ; i++)
    {
        for (int j = i+1 ; j <bodies.size() ; j++)
        {
            vector_3D r;
            
            r = bodies[j].position - bodies[i].position;
            double pe = (-G * bodies[i].mass * bodies[j].mass / (r.length()+ 1e-10) );
            bodies[i].PE += pe * 0.5;
            bodies[j].PE += pe * 0.5;

        }
    }
}

void simulator :: simulate_steps()
{
    for (body& b : bodies)
    {
        b.reset_acceleration();
        b.PE = 0.0;
    }

    calculate_forces();
    update_bodies();
    
    stepcount++;

}


void simulator :: simulate(double steps)
{
    
    double Total_Energy = 0;
    double initial_state = 0;
    
    ofstream log("stimulation_log.txt");
    log.precision(10);
    log.setf(ios :: scientific);

    for (double i = 0 ; i < steps ; i++)
    {
        

        double KE = 0.0;
        double PE = 0.0;
            simulate_steps();
            for(body& b : bodies)
                b.body_display(log);
            for (body& b : bodies)
            {
                KE = KE + b.KE;
                PE = PE + b.PE;
                

            }
            if (i == 0.0)
            initial_state = KE + PE;
           
            Total_Energy = KE + PE;
            
            

            
            log <<"Total Kinetic Energy  = " << KE << endl;
            log << "Total Potential Energy = "<< PE << endl;
            log <<"Total Energy          = " << Total_Energy << endl;
            log <<"Drift                 = " << abs(Total_Energy - initial_state) << endl;
            log <<"step count = " << stepcount << "  |  Time passed = " << stepcount * timestep / 86400 << " days" << endl;
            log << "--------------------------------------------------------------------------------------------------------" <<endl;
            
          
    }
    log.close();
}

