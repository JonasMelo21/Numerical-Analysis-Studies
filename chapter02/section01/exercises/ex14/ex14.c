/*
    Created by Jonas H. Melo on 2024/08/10
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's find a solution for x^3 + x - 4 = 0 with 10^(-3) digits of precision.
*/

#include <math.h>
#include <stdio.h>

double f(double x) {
    return pow(x, 3) + x - 4;
}

double bisection(double (*func)(double), double interval[2], double tol, int maxIterations) {
    double a = interval[0];
    double b = interval[1];
    double FA = func(a);
    double p;
    double FP;
    int i = 1;

    while (i <= maxIterations) {
        p = a + (b - a) / 2;
        FP = func(p);

        if (FP == 0 || (b - a) < tol) {
            printf("Procedure executed successfully after %d iterations\n", i);
            return p;
        } else if (FA * FP > 0) {
            a = p;
            FA = FP;
        } else {
            b = p;
        }
        i++;
    }

    if (i > maxIterations) {
        printf("\nProcedure failed after %d iterations\n", i);
        printf("Value of p found so far: %.3f\n", p);
        return -1;
    }

    return -1;  // Return statement added to handle all control paths
}

int main() {
    double interval[2] = {1, 4};  // Correct initialization of the interval
    double tol = pow(10, -3);
    int maxIterations = 50;
    double solution = bisection(f, interval, tol, maxIterations);
    printf("\nSolution for the equation x^3 + x - 4: %.3f\n", solution);

    return 0;
}
