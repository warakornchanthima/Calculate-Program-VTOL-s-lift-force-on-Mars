#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    // Input variables
    double mass;
    double g;
    double rho;
    double diameter;
    double rpm;
    double efficiency;
    double Ct;
    int rotor_count;

    // Calculated variables
    double weight;
    double area;
    double omega;
    double tip_speed;
    double induced_velocity;
    double induced_power;
    double actual_power;
    double torque;

    double n;
    double thrust_per_rotor;
    double total_thrust;
    double thrust_to_weight;

    printf("========================================\n");
    printf("       MARS VTOL ROTOR PERFORMANCE MODEL\n");
    printf("========================================\n\n");

    // Input
    printf("UAV mass (kg): ");
    scanf("%lf", &mass);

    printf("Mars gravity (m/s^2) [3.71]: ");
    scanf("%lf", &g);

    printf("Mars air density (kg/m^3) [0.016]: ");
    scanf("%lf", &rho);

    printf("Number of rotors: ");
    scanf("%d", &rotor_count);

    printf("Rotor diameter (m): ");
    scanf("%lf", &diameter);

    printf("Rotor speed (RPM): ");
    scanf("%lf", &rpm);

    printf("Thrust coefficient Ct [0.01]: ");
    scanf("%lf", &Ct);

    printf("Overall efficiency (0-1) [0.70]: ");
    scanf("%lf", &efficiency);


    // ========================================
    // BASIC PHYSICS
    // ========================================

    // Weight
    weight = mass * g;

    // Rotor disk area
    area = PI * pow(diameter, 2) / 4.0;

    // Angular velocity
    omega = 2.0 * PI * rpm / 60.0;

    // Rotor tip speed
    tip_speed = PI * diameter * rpm / 60.0;

    // Revolutions per second
    n = rpm / 60.0;


    // ========================================
    // MOMENTUM THEORY
    // ========================================

    // Induced velocity required for hover
    induced_velocity =
        sqrt(weight / (2.0 * rho * area * rotor_count));

    // Ideal induced power
    induced_power =
        weight * induced_velocity;

    // Actual power considering efficiency
    actual_power =
        induced_power / efficiency;

    // Torque
    torque =
        actual_power / omega;


    // ========================================
    // THRUST CALCULATION
    // ========================================

    // Thrust produced by one rotor
    thrust_per_rotor =
        Ct * rho * pow(n, 2) * pow(diameter, 4);

    // Total thrust from all rotors
    total_thrust =
        thrust_per_rotor * rotor_count;

    // Thrust-to-weight ratio
    thrust_to_weight =
        total_thrust / weight;


    // ========================================
    // RESULTS
    // ========================================

    printf("\n========================================\n");
    printf("                RESULTS\n");
    printf("========================================\n");

    printf("UAV mass             = %.3f kg\n", mass);

    printf("Mars gravity         = %.3f m/s^2\n", g);

    printf("Mars air density     = %.6f kg/m^3\n", rho);

    printf("Number of rotors     = %d\n", rotor_count);

    printf("Rotor diameter       = %.3f m\n", diameter);

    printf("Rotor RPM            = %.1f RPM\n", rpm);

    printf("Thrust coefficient   = %.4f\n", Ct);

    printf("\n----------------------------------------\n");

    printf("Weight               = %.3f N\n", weight);

    printf("Rotor area           = %.4f m^2\n", area);

    printf("Angular velocity     = %.3f rad/s\n", omega);

    printf("Tip speed            = %.3f m/s\n", tip_speed);

    printf("Rotational speed     = %.3f rev/s\n", n);

    printf("\n----------------------------------------\n");

    printf("Induced velocity     = %.3f m/s\n",
           induced_velocity);

    printf("Ideal induced power  = %.3f W\n",
           induced_power);

    printf("Estimated power      = %.3f W\n",
           actual_power);

    printf("Estimated torque     = %.4f N*m\n",
           torque);

    printf("\n----------------------------------------\n");

    printf("Thrust per rotor     = %.3f N\n",
           thrust_per_rotor);

    printf("Total thrust         = %.3f N\n",
           total_thrust);

    printf("Thrust-to-weight     = %.3f\n",
           thrust_to_weight);


    // ========================================
    // HOVER STATUS
    // ========================================

    printf("\n========================================\n");
    printf("              FLIGHT STATUS\n");
    printf("========================================\n");

    if (total_thrust < weight)
    {
        printf("Status: INSUFFICIENT THRUST\n");
        printf("UAV CANNOT HOVER.\n");
    }
    else if (total_thrust == weight)
    {
        printf("Status: HOVER CONDITION\n");
        printf("UAV CAN HOVER IDEALLY.\n");
    }
    else
    {
        printf("Status: SUFFICIENT THRUST\n");
        printf("UAV CAN HOVER IN PRINCIPLE.\n");
    }

    printf("========================================\n");

    return 0;
}
