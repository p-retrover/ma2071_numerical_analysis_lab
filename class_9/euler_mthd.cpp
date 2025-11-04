#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Example differential equation: dy/dx = x + y
double f(double x, double y) {
    return x + y;
}

int main() {
    double x0, y0, h, xn;

    cout << "Enter initial x0 and y0: ";
    cin >> x0 >> y0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter x at which to find y (xn): ";
    cin >> xn;

    cout << fixed << setprecision(6);
    cout << "\nEuler’s Method:\n";
    cout << "x\t\ty\n";

    while (x0 < xn) {
        y0 = y0 + h * f(x0, y0);
        x0 = x0 + h;
        cout << x0 << "\t" << y0 << endl;
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y0 << endl;
    return 0;
}

/*
This program expects the user to input the initial x0 and y0 values, the step size h, and the xn value at which to find y.
For example:
0 1
0.1
0.5
*/