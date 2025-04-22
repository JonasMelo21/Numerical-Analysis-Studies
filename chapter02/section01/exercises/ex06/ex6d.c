#include <math.h>
#include <stdio.h>

// Definindo a função x + 1 − 2 sin(πx)
double f(double x) {
    return x + 1 - 2 * sin(M_PI * x);
}

double bisectionMethod(double interval[2], double tol, int maxIterations, double (*func)(double)) {
    double a = interval[0];
    double b = interval[1];
    double FA = func(a);
    double FB = func(b);

    // F(a) and F(b) must have opposite signs
    if (FA * FB > 0) {
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
    double interval1[2] = {0, 0.5};
    double interval2[2] = {0.5, 1};
    double tol = pow(10, -5);

    double solution1 = bisectionMethod(interval1, tol, 30, f);
    if (solution1 != -1) {
        printf("\nSolution for the equation x + 1 - 2 sin(πx) on [0, 0.5]: %.5f\n", solution1);
    }

    
    double solution2 = bisectionMethod(interval2, tol, 30, f);
    if (solution2 != -1) {
        printf("\nSolution for the equation x + 1 - 2 sin(πx) on [0.5, 1]: %.5f\n", solution2);
    }

    return 0;
}
