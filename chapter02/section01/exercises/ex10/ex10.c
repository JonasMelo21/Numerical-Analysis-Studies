/*
    Created by Jonas H. Melo on 2024/07/31
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find which root for
    f(x) = (x + 2)(x + 1)^2(x − 1)^3(x − 2)
    is found in the intervals [−1.5, 2.5],[−0.5, 2.4],[−0.5, 3],[−3, −0.5].

*/

#include <stdio.h>
#include <math.h>

// Implementation of the function we want to find the root
double f(double x) {
    return (x + 2) * pow(x + 1, 2) * x * pow(x - 1, 3) * (x - 2);
}

// Implementation of bsection method technique
double bisectionMethod(double (*func)(double), double interval[2], double tol, int maxIterations) {
    // Initializing the interval endpoints(a,b) and the value in the middle of the interval(p)
    double a = interval[0];
    double FA = func(a);
    double b = interval[1];
    double p;

    // binary search until we find p such that F(p) = 0
    int i = 1;
    while (i <= maxIterations) {
        p = a + (b - a) / 2;
        double FP = func(p);

        // Procedure executed successfully(root found)
        if (FP == 0 || (b - a) / 2 < tol) {
            return p;
            break;
        } 
        // The root is between p and b so we change a value for next iteration
        else if (FP * FA > 0) {
            a = p;
            FA = FP;
        } 
        // The root is between a and p, so change b for next iteration
        else {
            b = p;
        }
        i++;
    }
    printf("Method failed after %d iterations\n", i);
    printf("Current value of p: %.5f\n", p);
    return p;
}

int main() {

    // Initializing the intervals of interest
    double interval1[2] = {-1.5, 2.5};
    double interval2[2] = {-0.5, 2.4};
    double interval3[2] = {-0.5, 3.0};
    double interval4[2] = {-3.0, -0.5};

    double tol = pow(10, -5);

    // Solution for bisection technique in each interval
    double x1 = bisectionMethod(f, interval1, tol, 50);
    double x2 = bisectionMethod(f, interval2, tol, 50);
    double x3 = bisectionMethod(f, interval3, tol, 50);
    double x4 = bisectionMethod(f, interval4, tol, 50);

    printf("\nSolution for f(x) = (x + 2)(x + 1)^2(x - 1)^3(x - 2)\n");
    printf("in the interval [-1.5, 2.5]: %.3f\n", x1);
    printf("in the interval [-0.5, 2.4]: %.3f\n", x2);
    printf("in the interval [-0.5, 3.0]: %.3f\n", x3);
    printf("in the interval [-3.0, -0.5]: %.3f\n", x4);
    
    return 0;
}
