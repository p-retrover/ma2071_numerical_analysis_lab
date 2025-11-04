#include <iostream>
#include <cmath>
using namespace std;

double iterat(double x1, double x2, double x3, int i) {
    i++;

    // g1(x) = (x^2 - 3)/2
    double y1 = (x1 * x1 - 3) / 2.0;

    // g2(x) = 3 / (x - 2)
    double y2 = 3.0 / (x2 - 2.0);

    // g3(x) = sqrt(2x + 3)
    double y3 = sqrt(2.0 * x3 + 3.0);

    double d = y3 - x3;

    cout << "After iteration no. " << i << ":\t"
         << y1 << "\t\t" << y2 << "\t\t" << y3 << endl;

    if (fabs(d) > 1e-5)
        return iterat(y1, y2, y3, i);  // continue iteration
    else
        return y3;  // converged
}

int main() {
    int i = 0;
    double x = 2.5, y;

    cout << "After iteration no. " << i
         << ":\tg1(x)\t\tg2(x)\t\tg3(x)\n";

    y = iterat(x, x, x, i);

    cout << "The answer is x = " << y << endl;
    return 0;
}

/*
This program does not take any user input. The initial value for the fixed-point iteration is hardcoded in the main function.
x = 2.5
*/
