#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i, j, k;
    int rhs = 0;
    float temp, var[10], coeff[10][10], pivratio = 0.0;

    cout << "\nGAUSS ELIMINATION METHOD";
    cout << "\nEnter the number of equations: ";
    cin >> n;

    // initialize variables
    for (i = 1; i <= n; i++)
        var[i] = 0.0;

    // input augmented matrix
    cout << "\nEnter the values of the coefficients to form the augmented matrix\n";
    for (i = 1; i <= n; i++) {
        cout << "\nEnter the coefficients of equation " << i << " : ";
        for (j = 1; j <= (n + 1); j++)
            cin >> coeff[i][j];
    }

    // display augmented matrix
    cout << "\nThe augmented matrix looks like:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++)
            cout << coeff[i][j] << "\t";
        cout << "\n";
    }

    // check if all RHS are zero
    for (i = 1; i <= n; i++)
        if (coeff[i][n + 1] == 0)
            rhs = rhs + 1;

    if (rhs == n) {
        cout << "\nThe matrix is singular";
        cout << "\nAll variables have solution = 0";
    } else {
        // Forward elimination
        for (i = 1; i <= (n - 1); i++) {
            for (j = i + 1; j <= n; j++) {
                pivratio = coeff[j][i] / coeff[i][i];
                coeff[j][i] = 0.0;
                for (k = i + 1; k <= (n + 1); k++)
                    coeff[j][k] = coeff[j][k] - (pivratio * coeff[i][k]);
            }
        }

        cout << "\nUpper Triangular Matrix:\n";
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= (n + 1); j++)
                cout << coeff[i][j] << "\t";
            cout << "\n";
        }

        // Back substitution
        for (i = n; i >= 1; i--) {
            temp = coeff[i][n + 1];
            for (j = i + 1; j <= n; j++)
                temp -= coeff[i][j] * var[j];
            var[i] = temp / coeff[i][i];
        }

        cout << "\nSolution:\n";
        for (i = 1; i <= n; i++)
            cout << "x" << i << " = " << var[i] << "\n";
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
