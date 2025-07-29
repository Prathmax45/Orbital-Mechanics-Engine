# 🌌 N-Body Simulation Project (Orbit Mechanics Engine)

This project simulates the gravitational interaction between celestial bodies — currently configured for the **Earth-Sun system** — using classical Newtonian mechanics. It demonstrates orbital dynamics, energy conservation, and numerical integration with high precision.

---

## 📁 Project Structure

```
Orbital-Mechanics-Engine/
├── vector_3D.h           # 3D vector class declaration
├── vector_3D.cpp         # Vector operations: +, -, *, dot, cross, normalize
├── body.h                # Body class declaration
├── body.cpp              # Body behavior: position, velocity, energy
├── simulator.h           # Simulator class declaration
├── simulator.cpp         # Core simulation loop, force calculations, energy
├── main.cpp              # Entry point — initializes Earth and Sun
└── stimulation_log.txt   # Output log (auto-generated)
```

---

## 🚀 Features

- Object-oriented simulation of gravitational forces  
- Newtonian mechanics and velocity Verlet integration  
- Custom 3D vector class with full mathematical operations  
- Tracks:
  - Position, velocity, acceleration  
  - Kinetic and potential energy  
  - Total energy and energy drift over time  
- Precision-aware floating-point arithmetic  
- Easily extensible to simulate more planets, moons, or stars  

---

## ⚙️ How to Configure

You can modify the simulation parameters in `main.cpp`:

```cpp
simulator s;
body earth(5.972e24, vector_3D(1.5e11, 0, 0), vector_3D(0, 29780, 0), "Earth");
body sun(1.989e30, vector_3D(0, 0, 0), vector_3D(0, 0, 0), "Sun");

s.addBody(sun);
s.addBody(earth);
s.simulate(10000); // Simulate for 10,000 steps
```

To adjust the simulation's time resolution:

```cpp
simulator() : G(6.67430e-11), timestep(10.0), stepcount(0.0) {}  // timestep in seconds
```

---

## 📊 Output: stimulation_log.txt

Each simulation step logs:

- Object state (mass, position, velocity, acceleration)  
- Total Kinetic Energy  
- Total Potential Energy  
- Total System Energy  
- Energy Drift (conservation check)  
- Elapsed simulation time (in days)  

Example snippet:

```
Object                = Earth
Mass                  = 5.972e+24
Position co-ordinates = (1.5e+11,29780,0)
Velocity              = (0.00590008,29780,0)
Acceleration          = (0.00590008,0,0)

Total Kinetic Energy  = 2.64813e+33
Total Potential Energy = -5.28529e+33
Total Energy           = -2.63716e+33
Drift                  = 0
step count = 1  |  Time passed = 1.15741e-05 days
```

---

## 🧠 Physics Principles

- **Gravitational Force**  
  F = (G * m1 * m2) / r²

- **Velocity Verlet Integration**  
  Used to update both position and velocity with better stability.

- **Energy Calculations**  
  - Kinetic Energy (KE) = 0.5 * m * v²  
  - Potential Energy (PE) = -G * m1 * m2 / r  

- **Conservation of Energy**  
  Drift is tracked to assess numerical stability.

---

## 🛠️ How to Compile and Run

### Compile:
```
g++ main.cpp vector_3D.cpp body.cpp simulator.cpp -o mENG
```

### Run:
```
./mENG
```

Then check the output in `stimulation_log.txt`.

---

## 🧪 Suggestions for Expansion

- Add more celestial bodies (e.g. Moon, Mars, satellites)  
- 3D visualization using Python (e.g., matplotlib or VPython)  
- Adaptive time-step or Runge-Kutta 4th order (RK4) integration  
- Export logs in CSV/JSON for plotting  
- Real-time GUI using Qt or SFML  
- GPU acceleration with CUDA/OpenCL for large N-body systems  

---

## 👨‍💻 Author

**Prathmesh Satish Kanure**  
Built for academic and research purposes, to explore space mechanics and high-precision floating-point simulation.

---

## 🪐 License

Open for educational and research use. Attribution appreciated.
