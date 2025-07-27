#include "simulator.h"
#include "body.h"
#include "vector_3D.h"


int main() {
    simulator s;
    body earth(5.972e24, vector_3D(1.5e11,0,0), vector_3D(0,29780,0), "Earth");
    body sun(1.989e30, vector_3D(0,0,0), vector_3D(0, -0.0000898675, 0 ), "Sun");

    // Sun
    s.addBody(sun);
    // Earth
    s.addBody(earth);

    s.simulate(100000); // 1000 steps of 1 min each
}