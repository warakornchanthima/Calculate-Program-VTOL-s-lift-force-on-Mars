#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    double mass;
    double g;
    double rho;
    double diameter;
    double rpm;
    double efficiency;

    double weight;
    double area;
    double omega;
    double tip_speed;

    double induced_velocity;
    double induced_power;
    double actual_power;
    double torque;

    printf("========================================\n");
    printf("   MARS VTOL ROTOR PERFORMANCE MODEL\n");
    printf("========================================\n\n");

    printf("UAV mass (kg): ");
    scanf("%lf", &mass);

    printf("Mars gravity (m/s^2) [3.73]: ");
    scanf("%lf", &g);

    printf("Mars air density (kg/m^3) [0.016]: ");
    scanf("%lf", &rho);

    printf("Rotor diameter (m): ");
    scanf("%lf", &diameter);

    printf("Rotor speed (RPM): ");
    scanf("%lf", &rpm);

    printf("Overall efficiency (0-1) [0.70]: ");
    scanf("%lf", &efficiency);

    /* Weight */
    weight = mass * g;

    /* Rotor disk area */
    area = PI * pow(diameter, 2) / 4.0;

    /* Angular velocity */
    omega = 2.0 * PI * rpm / 60.0;

    /* Rotor tip speed */
    tip_speed = PI * diameter * rpm / 60.0;

    /*
       Momentum theory:
       T = 2 * rho * A * vi^2

       Therefore:
       vi = sqrt(T / (2*rho*A))
    */

    induced_velocity =
        sqrt(weight / (2.0 * rho * area));

    /* Ideal induced power */
    induced_power =
        weight * induced_velocity;

    /* Correct for efficiency */
    actual_power =
        induced_power / efficiency;

    /* Torque = Power / angular velocity */
    torque =
        actual_power / omega;

    printf("\n========================================\n");
    printf("              RESULTS\n");
    printf("========================================\n");

    printf("UAV mass             = %.3f kg\n", mass);
    printf("Mars gravity         = %.3f m/s^2\n", g);
    printf("Mars air density     = %.6f kg/m^3\n", rho);

    printf("\nWeight               = %.3f N\n", weight);
    printf("Rotor area           = %.4f m^2\n", area);

    printf("Rotor diameter       = %.3f m\n", diameter);
    printf("Rotor RPM            = %.1f RPM\n", rpm);

    printf("Angular velocity     = %.3f rad/s\n", omega);
    printf("Tip speed            = %.3f m/s\n", tip_speed);

    printf("\nInduced velocity     = %.3f m/s\n", induced_velocity);

    printf("Ideal induced power  = %.3f W\n",induced_power);

    printf("Estimated power      = %.3f W\n",actual_power);

    printf("Estimated torque     = %.4f N*m\n", torque);

    printf("\n========================================\n");

    return 0;
}