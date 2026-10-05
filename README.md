Mars VTOL Rotor Performance Model

A C program for estimating the aerodynamic and power requirements of a Vertical Take-Off and Landing (VTOL) Unmanned Aerial Vehicle (UAV) designed for operation in the Martian atmosphere.

The program uses momentum theory to estimate rotor performance during hover, including required thrust, rotor disk area, induced velocity, power, angular velocity, rotor tip speed, and torque.

Project Overview

Designing a VTOL UAV for Mars is significantly different from designing a conventional drone for Earth.

Mars has a much thinner atmosphere than Earth, which means that the rotor must accelerate a relatively small amount of atmospheric mass to generate sufficient lift.

This project provides a simplified mathematical model that can be used as an initial tool for studying the rotor requirements of a Mars VTOL UAV.

The program is intended for preliminary analysis and educational/research purposes.

Features

The program calculates:

UAV weight on Mars
Rotor disk area
Rotor angular velocity
Rotor tip speed
Induced velocity
Ideal induced power
Estimated actual power
Estimated rotor torque

The user can enter:

UAV mass
Mars gravitational acceleration
Mars atmospheric density
Rotor diameter
Rotor speed (RPM)
Overall system efficiency
Physics Model
1. Weight

The weight of the UAV on Mars is calculated using:

[
W = mg
]

Where:

W = Weight (N)
m = UAV mass (kg)
g = Mars gravitational acceleration (m/s²)

The default value used by the program is:

[
g = 3.73;m/s^2
]

2. Rotor Disk Area

The rotor disk area is calculated using:

[
A = \frac{\pi D^2}{4}
]

Where:

A = Rotor disk area (m²)
D = Rotor diameter (m)
3. Angular Velocity

Rotor angular velocity is calculated from RPM:

[
\omega = \frac{2\pi RPM}{60}
]

Where:

(\omega) = Angular velocity (rad/s)
RPM = Rotor speed (revolutions per minute)
4. Rotor Tip Speed

The approximate rotor tip speed is:

[
V_{tip} = \frac{\pi D RPM}{60}
]

Where:

(V_{tip}) = Rotor tip speed (m/s)
D = Rotor diameter (m)
RPM = Rotor speed (RPM)
Momentum Theory

The program uses ideal rotor momentum theory for hover.

The relationship between thrust and induced velocity is:

[
T = 2\rho A v_i^2
]

Therefore:

[
v_i =
\sqrt{\frac{T}{2\rho A}}
]

Where:

T = Rotor thrust (N)
(\rho) = Atmospheric density (kg/m³)
A = Rotor disk area (m²)
(v_i) = Induced velocity (m/s)

For basic hover analysis, the required thrust is approximated as the UAV's weight:

[
T \approx W = mg
]

Therefore, the program calculates:

[
v_i =
\sqrt{\frac{mg}{2\rho A}}
]

Induced Power

The ideal induced power is:

[
P_i = T v_i
]

For hover:

[
P_i = Wv_i
]

Where:

(P_i) = Ideal induced power (W)
T = Required thrust (N)
(v_i) = Induced velocity (m/s)
Estimated Actual Power

Real rotor systems have losses caused by:

Rotor aerodynamic losses
Motor losses
Electronic speed controller losses
Mechanical losses
Propeller/rotor profile drag

The program therefore applies an overall efficiency factor:

[
P_{actual} =
\frac{P_i}{\eta}
]

Where:

(P_{actual}) = Estimated actual power (W)
(P_i) = Ideal induced power (W)
(\eta) = Overall efficiency

The default efficiency suggested by the program is:

[
\eta = 0.70
]

This value is only an engineering assumption for preliminary calculations and should be replaced with experimentally measured or validated system efficiency for a real design.

Rotor Torque

The approximate rotor torque is calculated using:

[
Q = \frac{P}{\omega}
]

Where:

Q = Torque (N·m)
P = Rotor power (W)
(\omega) = Angular velocity (rad/s)

The program uses the estimated actual power:

[
Q =
\frac{P_{actual}}{\omega}
]

Mars Environmental Parameters

The program allows the user to enter Mars atmospheric parameters manually.

Typical starting values used for the model are:

Parameter	Value	Unit
Mars gravity	3.73	m/s²
Mars atmospheric density	0.016	kg/m³

These values are representative values for preliminary calculations. Actual Martian atmospheric density varies with altitude, location, temperature, season, and atmospheric conditions.

Program Flow
UAV Mass
   │
   ▼
Mars Gravity
   │
   ▼
Required Weight / Thrust
   │
   ▼
Rotor Diameter
   │
   ▼
Rotor Disk Area
   │
   ▼
Induced Velocity
   │
   ▼
Induced Power
   │
   ▼
System Efficiency
   │
   ▼
Estimated Power
   │
   ├──────────────┐
   ▼              ▼
RPM          Angular Velocity
   │              │
   ▼              │
Tip Speed         │
   │              ▼
   └──────────► Torque
Example Input
UAV mass (kg): 1.8
Mars gravity (m/s^2): 3.73
Mars air density (kg/m^3): 0.016
Rotor diameter (m): 1.2
Rotor speed (RPM): 2800
Overall efficiency (0-1): 0.70

The program then calculates:

Weight
Rotor area
Angular velocity
Rotor tip speed
Induced velocity
Ideal induced power
Estimated power
Estimated torque
Compilation
GCC

Compile the program using:

gcc mars_vtol_rotor.c -o mars_vtol_rotor -lm

Run:

./mars_vtol_rotor
Windows

If using MinGW GCC:

gcc mars_vtol_rotor.c -o mars_vtol_rotor.exe -lm

Then:

mars_vtol_rotor.exe
Limitations

This program is a simplified preliminary model.

It does not currently model:

Blade Element Momentum Theory (BEMT)
Blade chord distribution
Blade pitch angle
Blade twist
Airfoil lift coefficient (C_L)
Airfoil drag coefficient (C_D)
Reynolds number variation
Mach number
Rotor solidity
Number of blades
Rotor–rotor aerodynamic interaction
Ground effect
Mars atmospheric temperature variation
Dust effects
Motor efficiency as a function of RPM
Battery voltage and capacity
Structural loads
Dynamic stability
Full VTOL flight dynamics

Therefore, the calculated values should not be treated as final specifications for a flight-ready aircraft.

Future Development

Future versions of this project may include:

Version 2
Automatic RPM calculation
Rotor thrust coefficient (C_T)
Power coefficient (C_P)
Rotor solidity
Blade pitch estimation
Motor power requirement
Battery energy estimation
Version 3

Implementation of Blade Element Momentum Theory (BEMT):

Rotor Diameter
      │
      ▼
Blade Geometry
      │
      ├── Chord
      ├── Pitch
      ├── Twist
      └── Number of Blades
      │
      ▼
Airfoil Data
      │
      ├── CL
      └── CD
      │
      ▼
Blade Element Analysis
      │
      ▼
BEMT Iteration
      │
      ├── Thrust
      ├── Torque
      └── Power

This would provide a more detailed rotor design model suitable for engineering analysis.

Applications

This project can be used as a starting point for research involving:

Mars VTOL UAVs
Planetary exploration aircraft
Rotorcraft aerodynamics
Low-density atmospheric flight
UAV propulsion systems
Aerospace engineering
C/C++ engineering simulations
Physics-based UAV design
Project Objective

The long-term objective is to develop a computational model for a VTOL UAV intended to perform Martian surface exploration and plant-related missions, such as surveying terrain and supporting experimental plant propagation or seed deployment.

The computational model can eventually be integrated with a larger flight-dynamics and autonomous-control simulation.

Technologies
Language: C
Compiler: GCC / MinGW
Mathematical Library: <math.h>
Model: Ideal Momentum Theory
Application: Mars VTOL UAV preliminary design
License

This project is intended for educational and research purposes.

You may modify and extend the source code for non-commercial educational, academic, and experimental projects.

Author

Mars VTOL UAV Research Project

A computational study of rotor performance and propulsion requirements for a VTOL UAV operating in the Martian atmosphere.
