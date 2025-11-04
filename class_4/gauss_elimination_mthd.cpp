#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "GAUSS ELIMINATION METHOD\n";
    cout << "Enter the number of equations: ";
    cin >> n;

    double coeff[20][20], var[20], temp, pivratio;

    // Input augmented matrix
    cout << "\nEnter the augmented matrix (coefficients + constants):\n";
    for (int i = 1; i <= n; i++) {
        cout << "Equation " << i << ": ";
        for (int j = 1; j <= n + 1; j++) {
            cin >> coeff[i][j];
        }
    }

    // Display augmented matrix
    cout << "\nThe augmented matrix is:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cout << setw(10) << coeff[i][j] << " ";
        }
        cout << "\n";
    }

    // Forward elimination
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (coeff[i][i] == 0) {
                cout << "Mathematical Error: Zero pivot element.\n";
                return 1;
            }
            pivratio = coeff[j][i] / coeff[i][i];
            for (int k = i; k <= n + 1; k++) {
                coeff[j][k] -= pivratio * coeff[i][k];
            }
        }
    }

    // Display upper triangular matrix
    cout << "\nUpper Triangular Matrix after elimination:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cout << setw(10) << coeff[i][j] << " ";
        }
        cout << "\n";
    }

    // Back substitution
    for (int i = n; i >= 1; i--) {
        temp = coeff[i][n + 1];
        for (int j = i + 1; j <= n; j++) {
            temp -= coeff[i][j] * var[j];
        }
        var[i] = temp / coeff[i][i];
    }

    // Output solution
    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++) {
        cout << "x" << i << " = " << fixed << setprecision(6) << var[i] << endl;
    }

    return 0;
}

/*
This program expects the user to input the number of equations and the coefficients of the augmented matrix.
For example, for a 2x2 system:
2
2 1 5
3 2 8
*/
