#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define functions
double f1(double x, double y) { return pow(x, 3) + y - 1; }
double f2(double x, double y) { return pow(y, 3) - x + 1; }

// Partial derivatives (Jacobian)
double f1x(double x, double y) { return 3 * x * x; }  // ∂f1/∂x
double f1y(double x, double y) { return 1; }          // ∂f1/∂y
double f2x(double x, double y) { return -1; }         // ∂f2/∂x
double f2y(double x, double y) { return 3 * y * y; }  // ∂f2/∂y

int main() {
    cout << "Newton's Method for solving system of equations\n";

    double x, y;
    cout << "Enter initial guesses for x and y: ";
    cin >> x >> y;

    int maxIter = 20;
    double tol = 1e-6;

    for (int iter = 1; iter <= maxIter; iter++) {
        // Function values
        double F1 = f1(x, y);
        double F2 = f2(x, y);

        // Jacobian matrix
        double J11 = f1x(x, y), J12 = f1y(x, y);
        double J21 = f2x(x, y), J22 = f2y(x, y);

        // Determinant
        double det = J11 * J22 - J12 * J21;
        if (fabs(det) < 1e-12) {
            cout << "Jacobian is singular. Stopping.\n";
            break;
        }

        // Inverse of 2x2 Jacobian * F
        double dx = (-F1 * J22 + F2 * J12) / det;
        double dy = (-J11 * F2 + J21 * F1) / det;

        // Update guesses
        x += dx;
        y += dy;

        cout << "Iteration " << iter << ": x = " 
             << fixed << setprecision(6) << x 
             << ", y = " << y 
             << " | dx = " << dx << ", dy = " << dy << endl;

        // Check convergence
        if (fabs(dx) < tol && fabs(dy) < tol) {
            cout << "Converged to solution.\n";
            break;
        }
    }

    cout << "Final solution: x = " << x << ", y = " << y << endl;
    return 0;
}

/*
This program expects the user to input initial guesses for x and y.
For example:
-0.5
0.5
*/
