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

    s.addBody(moon);
    s.addBody(sun);
    s.addBody(earth);

    s.simulate(525600.0); //  60 sec timestep  

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double>elapsed = end - start;

    std:: cout << "Elapsed Time : " << elapsed.count() << " sec" << std::endl;

    return 0;
}