#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define the function
float f(float x) {
    return pow(x, 3) + x - 1; // Equation: x^3 + x - 1
}

void secant(float x1, float x2, float E) {
    float x0, f1, f2;
    int n = 0;

    do {
        f1 = f(x1);
        f2 = f(x2);

        if (f2 - f1 == 0) {
            cout << "Division by zero error in secant formula." << endl;
            return;
        }

        x0 = (x1 * f2 - x2 * f1) / (f2 - f1);

        // Update values
        x1 = x2;
        x2 = x0;
        n++;

    } while (fabs(f(x2) - f(x1)) >= E);

    cout << fixed << setprecision(10);
    cout << "Root of the equation = " << x0 << endl;
    cout << "Number of iterations = " << n << endl;
}

int main() {
    float x1 = 0, x2 = 1, E = 1e-7;
    secant(x1, x2, E);
    return 0;
}

/*
This program does not take any user input. The initial values for the secant method are hardcoded in the main function.
x1 = 0
x2 = 1
E = 1e-7
*/
