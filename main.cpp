#include "simulator.h"
#include "body.h"
#include "vector_3D.h"
#include <chrono>


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    simulator s;
    body earth(5.972e24, vector_3D(1.5e11,0,0), vector_3D(0,29780,0), "Earth");
    body sun(1.989e30, vector_3D(0,0,0), vector_3D(0, -0.0000898675, 0 ), "Sun");
    body moon(7.348e22,vector_3D(1.5e11 + 384400000, 0, 0),vector_3D(0, 29780 + 1022, 0),"Moon");
    body mars(6.417e23, vector_3D(2.279e11, 0, 0), vector_3D(0, 24070, 0), "Mars");
    body jupiter(1.898e27, vector_3D(7.785e11, 0, 0), vector_3D(0, 13070, 0), "Jupiter");
    body saturn(5.683e26, vector_3D(1.433e12, 0, 0), vector_3D(0, 9690, 0), "Saturn");

    s.addBody(moon);
    s.addBody(sun);
    s.addBody(earth);
    s.addBody(mars);
    s.addBody(jupiter);
    s.addBody(saturn);

    s.simulate(525600.0); //  60 sec timestep  

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double>elapsed = end - start;

    std:: cout << "Elapsed Time : " << elapsed.count() << " sec" << std::endl;

    return 0; 
}