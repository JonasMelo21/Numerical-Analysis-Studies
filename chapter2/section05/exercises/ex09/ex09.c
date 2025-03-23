/*
    This code was created by Jonas H Melo on 2025/02/10
    This file is protected under MIT license

    This code is part of my studies on the field of Numerical Analysis
    Following the Section 05 from Chapter 02 from the text book 
    "Numerical Analysis" by Richard L Burden and Douglas J Faires
    
    Approach:
    The question wants us to use Stefesen's Method and  find a solution with 10^(-4) of accuraccy
    for the value of sqrt(3).
*/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return sqrt(3);
}

double steffensenMethod(double p0, double tolerance, int maxIterations) {
    int i = 1;
    while (i <= maxIterations) {
        double p1 = f(p0);
        double p2 = f(p1);
        double denominator = p2 - 2 * p1 + p0;
        
        if (fabs(denominator) < 1e-10) {
            printf("\nSteffensen Method Failed: Division by near-zero detected (iteration %d)\n", i);
            return -1;
        }

        double p = p0 - pow((p1 - p0), 2) / denominator;

        if (fabs(p - p0) < tolerance) {
            printf("\nSteffensen Method Success (%d iterations)\n", i);
            return p;
        }

        p0 = p;
        i++;
    }

    printf("\nSteffensen Method Failed: Maximum iterations reached\n");
    return -1;
}

int main() {
    double tolerance = pow(10,-5);
    double p0 = 2;
    int max = 50;

    double solution = steffensenMethod(p0, tolerance, max);
    
    if (solution != -1) {
        printf("\nSolution (Root): %.5f\n", solution);
    }

    return 0;
}
