#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    float x[50], f[50];  // simple static arrays (could use vector too)
    cout << "Enter x and f(x) values:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "f(x[" << i << "]): ";
        cin >> f[i];
    }

    float y;
    cout << "Enter the value of y to interpolate f(y): ";
    cin >> y;

    float l[50];   // Lagrange basis coefficients
    for (int j = 0; j < n; j++) {
        float num = 1.0, den = 1.0;
        for (int i = 0; i < n; i++) {
            if (i != j) {
                num *= (y - x[i]);
                den *= (x[j] - x[i]);
            }
        }
        l[j] = num / den;
        cout << "L[" << j << "] = " << l[j] << endl;
    }

    float p = 0.0f; // Interpolated result
    for (int i = 0; i < n; i++) {
        p += l[i] * f[i];
    }

    cout << "\nf(" << y << ") = " << p << endl;

    return 0;
}

/*
This program expects the user to input the number of data points, the data points themselves (x and f(x) values), and the value of y to interpolate.
For example:
4
0 0
1 1
2 8
3 27
2.5
*/
