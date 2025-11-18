#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to solve a system of linear equations Ay = x using Gaussian elimination
vector<double> solveLinearSystem(vector<vector<double>> A, vector<double> x) {
    int n = A.size();

    // Create augmented matrix
    for (int i = 0; i < n; ++i) {
        A[i].push_back(x[i]);
    }

    // Forward elimination
    for (int i = 0; i < n; ++i) {
        // Find pivot
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(A[j][i]) > abs(A[pivot][i])) {
                pivot = j;
            }
        }
        swap(A[i], A[pivot]);

        // Check for singular matrix
        if (abs(A[i][i]) < 1e-12) {
            cerr << "Error: Matrix is singular." << endl;
            return vector<double>();
        }

        // Normalize pivot row
        double div = A[i][i];
        for (int j = i; j <= n; ++j) {
            A[i][j] /= div;
        }

        // Eliminate other rows
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double mult = A[j][i];
                for (int k = i; k <= n; ++k) {
                    A[j][k] -= mult * A[i][k];
                }
            }
        }
    }

    // Back substitution (not needed for Gauss-Jordan)
    vector<double> y(n);
    for (int i = 0; i < n; ++i) {
        y[i] = A[i][n];
    }

    return y;
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
    double tol = 1e-6;
    double lambda_old = 0.0, lambda_new = 0.0;

    cout << "\nIter\tEigenvalue\n";
    for (int iter = 1; iter <= maxIter; ++iter) {
        // Solve Ay = x for y
        vector<double> y = solveLinearSystem(A, x);
        if (y.empty()) {
            return 1;
        }

        // Compute new eigenvalue approximation for A_inv
        double lambda_inv = y[0] / x[0];
        
        // The eigenvalue of A is the reciprocal
        lambda_new = 1.0 / lambda_inv;

        // Normalize y to avoid overflow/underflow
        double y_norm = norm(y);
        for (int i = 0; i < n; ++i)
            x[i] = y[i] / y_norm;

        cout << iter << "\t" << fixed << setprecision(6) << lambda_new << endl;

        // Check convergence
        if (fabs(lambda_new - lambda_old) < tol)
            break;

        lambda_old = lambda_new;
    }

    cout << "\nSmallest Eigenvalue ≈ " << fixed << setprecision(6) << lambda_new << endl;
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
2 -1 0
-1 2 -1
0 -1 2
1
1
1
*/
