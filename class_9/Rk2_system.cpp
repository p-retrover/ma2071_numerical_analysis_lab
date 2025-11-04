#include <iostream>
#include <iomanip>
using namespace std;

// Example system:
// dy1/dx = y2
// dy2/dx = -y1
// (Simple harmonic oscillator)

double f1(double x, double y1, double y2) {
    return y2;
}

double f2(double x, double y1, double y2) {
    return -y1;
}

int main() {
    double x0, y1, y2, h, xn;
    cout << "Enter initial x0, y1(0), y2(0): ";
    cin >> x0 >> y1 >> y2;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter final x value xn: ";
    cin >> xn;

    cout << fixed << setprecision(6);
    cout << "\n2nd Order Runge–Kutta (System of 2 ODEs)\n";
    cout << "x\t\ty1\t\ty2\n";

    while (x0 < xn) {
        // Compute k-values for RK2 (Heun’s method)
        double k1_1 = h * f1(x0, y1, y2);
        double k1_2 = h * f2(x0, y1, y2);

        double k2_1 = h * f1(x0 + h, y1 + k1_1, y2 + k1_2);
        double k2_2 = h * f2(x0 + h, y1 + k1_1, y2 + k1_2);

        // Update y1, y2
        y1 = y1 + 0.5 * (k1_1 + k2_1);
        y2 = y2 + 0.5 * (k1_2 + k2_2);
        x0 += h;

        cout << x0 << "\t" << y1 << "\t" << y2 << endl;
    }

    cout << "\nApproximate solution at x = " << xn << ":\n";
    cout << "y1 = " << y1 << ", y2 = " << y2 << endl;
    return 0;
}

/*
This program expects the user to input the initial x0, y1(0), y2(0) values, the step size h, and the final xn value.
For example:
0 0 1
0.1
0.5
*/