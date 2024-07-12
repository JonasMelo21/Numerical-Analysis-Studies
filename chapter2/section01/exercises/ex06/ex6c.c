#include <math.h>
#include <stdio.h>

// Implementing the function x^2 − 4x + 4 − ln(x)
double f(double x) {
    return pow(x, 2) - 4 * x + 4 - log(x);
}

double bisectionMethod(double interval[2], double tol, int maxIterations, double (*func)(double)) {
    double a = interval[0];
    double b = interval[1];
    double FA = func(a);

    // F(a) and F(b) must have opposite signs
    if (FA * func(b) > 0) {
        printf("\nThe values of the function for the endpoints a and b must have opposite signs\n");
        return -1;
    }

    for (int i = 1; i <= maxIterations; i++) {
        // Initializing the midpoint between the endpoints a and b
        double p = a + (b - a) / 2;
        double FP = func(p);

        // Procedure completed successfully
        if (FP == 0 || (b - a) / 2 < tol) {
            return p;
        }

        // The value of p such that F(p) = 0 is between p and b, so the new interval for the search is [p, b]
        if (FA * FP > 0) {
            a = p;
            FA = FP;
        } 
        // The value of p such that F(p) = 0 is between a and p, so the new interval is [a, p]
        else {
            b = p;
        }
    }
    printf("Procedure failure after %d iterations\n", maxIterations);
    return -1;
}

int main() {
    double interval[2] = {1, 2};
    double tol = pow(10, -5);
    double solution = bisectionMethod(interval, tol, 30, f);
    if (solution != -1) {
        printf("\nSolution for the equation x^2 - 4x + 4 - ln(x) on [1,2]: %.5f\n", solution);
    }
    return 0;
}
