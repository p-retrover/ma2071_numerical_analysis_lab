#include <iostream>
#include <cmath>
using namespace std;

#define EP 0.0001  // Smaller epsilon for better precision

// A function with a real root
double solution(double x) {
   return x*x*x + x - 1;  // Example: f(x) = x^3 + x - 1
}

void bisection(double a, double b) {
   if (solution(a) * solution(b) >= 0) {
      cout << "You have not assumed correct a and b\n";
      return;
   }

   double c;
   int iterations = 0;

   while ((b - a) >= EP) {
      c = (a + b) / 2;
      double fc = solution(c);

      if (fc == 0.0)
         break;

      if (solution(a) * fc < 0)
         b = c;
      else
         a = c;

      iterations++;
   }

   cout << "The value of root is : " << c << endl;
   cout << "Found in " << iterations << " iterations." << endl;
}

int main() {
   double a = 0, b = 1;
   bisection(a, b);
   return 0;
}

/*
This program does not take any user input. The initial values for the bisection method are hardcoded in the main function.
a = 0
b = 1
*/
