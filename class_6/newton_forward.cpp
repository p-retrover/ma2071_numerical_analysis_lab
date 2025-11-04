#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    float x[50], y[50][50];

    cout << "Enter x and f(x) values:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "f(x[" << i << "]): ";
        cin >> y[i][0];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    float value;
    cout << "\nEnter value of x to interpolate f(x): ";
    cin >> value;

    float h = x[1] - x[0];
    float p = (value - x[0]) / h;
    float result = y[0][0];
    float term = 1.0;

    for (int j = 1; j < n; j++) {
        term = term * (p - (j - 1)) / j;
        result += term * y[0][j];
    }

    cout << "\nf(" << value << ") = " << result << endl;

    return 0;
}

/*
This program expects the user to input the number of data points, the data points themselves (x and f(x) values), and the value of x to interpolate.
For example:
4
0 0
1 1
2 8
3 27
2.5
*/
