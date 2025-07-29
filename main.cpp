#include "simulator.h"
#include "body.h"
#include "vector_3D.h"


int main() {
    simulator s;
    body earth(5.972e24, vector_3D(1.5e11,0,0), vector_3D(0,29780,0), "Earth");
    body sun(1.989e30, vector_3D(0,0,0), vector_3D(0, -0.0000898675, 0 ), "Sun");
    body moon(
    7.348e22,  // Moon mass in kg
    vector_3D(1.5e11 + 384400000, 0, 0),  // Moon is ~384,400 km from Earth (in x-direction)
    vector_3D(0, 29780 + 1022, 0),  // Earth's orbital speed + Moon's relative speed (~1022 m/s)
    "Moon"
);

    s.addBody(moon);
    s.addBody(sun);
    s.addBody(earth);

    s.simulate(525600.0); //  60 sec timestep 
}