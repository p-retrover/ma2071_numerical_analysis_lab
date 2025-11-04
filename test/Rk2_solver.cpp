#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

using namespace std;

// This file follows the same structure as the RK2 solver in class_9:
// - separate functions f0,f1,f2 that give the RHS of the 1st-order system
// - a rk2_step that advances the 3-component state using RK2 (midpoint)
// - a simple interactive main that asks user for h and a single x and prints f'(x)

// Problem: f''' + 0.5 * f * f'' = 0
// Convert to system:
// u0 = f
// u1 = f'
// u2 = f''
// u0' = u1
// u1' = u2
// u2' = -0.5 * u0 * u2

using State = array<double,3>;

// RHS components (same style as class_9 functions f1,f2,...)
double f0(double /*t*/, const State &u) { // u0' = u1
    return u[1];
}
double f1(double /*t*/, const State &u) { // u1' = u2
    return u[2];
}
double f2(double /*t*/, const State &u) { // u2' = -0.5 * u0 * u2
    return -0.5 * u[0] * u[2];
}

// RK2 (midpoint) step for 3-component system
void rk2_step(State &u, double t, double h) {
    State k1, k2, tmp;
    k1[0] = f0(t, u);
    k1[1] = f1(t, u);
    k1[2] = f2(t, u);
    for (int i = 0; i < 3; ++i) tmp[i] = u[i] + 0.5 * h * k1[i];

    k2[0] = f0(t + 0.5 * h, tmp);
    k2[1] = f1(t + 0.5 * h, tmp);
    k2[2] = f2(t + 0.5 * h, tmp);

    for (int i = 0; i < 3; ++i) u[i] += h * k2[i];
}

int main() {
    cout << "Enter step size h (e.g. 0.2): ";
    double h;
    if (!(cin >> h) || h <= 0.0) {
        cerr << "Invalid step size\n";
        return 1;
    }

    cout << "Enter x where you want f'(x): ";
    double x;
    if (!(cin >> x) || x < 0.0) {
        cerr << "Invalid x\n";
        return 1;
    }

    // initial conditions at x=0
    State u = {0.0, 0.0, 0.332};

    if (x == 0.0) {
        cout << fixed << setprecision(6);
        cout << "f'(0) = " << u[1] << "\n";
        return 0;
    }

    int steps = static_cast<int>(round(x / h));
    double t = 0.0;

    for (int i = 1; i <= steps; ++i) {
        rk2_step(u, t, h);
        t += h;
    }

    cout << fixed << setprecision(6);
    cout << "Requested x = " << x << " (integrated to t = " << t << ")\n";
    cout << "f'(" << x << ") ≈ " << u[1] << "\n";
    return 0;
}