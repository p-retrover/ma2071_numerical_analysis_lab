#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Function to multiply a matrix with a vector
vector<double> multiplyMatrixVector(const vector<vector<double>> &A, const vector<double> &x) {
    int n = A.size();
    vector<double> result(n, 0.0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i] += A[i][j] * x[j];
    return result;
}

// Function to compute the Euclidean norm (magnitude) of a vector
double norm(const vector<double> &v) {
    double sum = 0.0;
    for (double val : v)
        sum += val * val;
    return sqrt(sum);
}

int main() {
    int n;
    cout << "Enter the order of the square matrix: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Enter the elements of the matrix A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<double> x(n);
    cout << "Enter the initial guess vector (size " << n << "):\n";
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    int maxIter = 1000;
    double tol = 1e-3;
    double lambda_old = 0.0, lambda_new = 0.0;

    cout << "\nIter\tEigenvalue\n";
    for (int iter = 1; iter <= maxIter; ++iter) {
        // Multiply A * x
        vector<double> y = multiplyMatrixVector(A, x);

        // Compute new eigenvalue approximation (Rayleigh quotient)
        lambda_new = y[0] / x[0];

        // Normalize y to avoid overflow/underflow
        double y_norm = norm(y);
        for (int i = 0; i < n; ++i)
            x[i] = y[i] / y_norm;

        cout << iter << "\t" << lambda_new << endl;

        // Check convergence
        if (fabs(lambda_new - lambda_old) < tol)
            break;

        lambda_old = lambda_new;
    }

    cout << "\nDominant Eigenvalue ≈ " << lambda_new << endl;
    cout << "Corresponding Eigenvector ≈ [ ";
    for (double val : x)
        cout << val << " ";
    cout << "]\n";

    return 0;
}

/*
This program expects the user to input the order of the square matrix, the elements of the matrix, and the initial guess vector.
For example:
3
1 2 0
2 1 0
0 0 5
1 1 1
*/
