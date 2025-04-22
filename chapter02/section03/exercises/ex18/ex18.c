/*
 * Created by: Jonas H. Melo
 * Created on: 2024/11/21
 * License: MIT
 *
 * Description:
 * This file is part of my numerical analysis studies, based on
 * Section 3 of Chapter 2 from the book "Numerical Analysis"
 * by Richard L. Burden and J. Douglas Faires, 11th edition.
 *
 * Objective:
 * 
 */

#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

// Function f(x) = tan(πx) - 6
double f(double x) {
    return tan(PI * x) - 6;
}

// Bisection Method
double bisectionMethod(double p0, double p1, int maxIter) {
    double p, f0, f1;
    for (int i = 1; i <= maxIter; i++) {
        f0 = f(p0);
        f1 = f(p1);
        p = (p0 + p1) / 2;
        if (f(p) == 0) {
            return p;
        }
        if (f(p) * f0 < 0) {
            p1 = p;
        } else {
            p0 = p;
        }
    }
    return p; // Root approximation after max iterations
}

// False Position (Regula Falsi) Method
double falsePositionMethod(double p0, double p1, int maxIter) {
    double p, f0, f1;
    for (int i = 1; i <= maxIter; i++) {
        f0 = f(p0);
        f1 = f(p1);
        p = p1 - (f1 * (p1 - p0)) / (f1 - f0);
        if (f(p) == 0) {
            return p;
        }
        if (f(p) * f0 < 0) {
            p1 = p;
        } else {
            p0 = p;
        }
    }
    return p; // Root approximation after max iterations
}

// Secant Method
double secantMethod(double p0, double p1, int maxIter) {
    double p;
    for (int i = 1; i <= maxIter; i++) {
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if (f(p) == 0) {
            return p;
        }
        p0 = p1;
        p1 = p;
    }
    return p; // Root approximation after max iterations
}

int main() {
    double p0 = 0, p1 = 0.48;
    int maxIter = 10;

    // Apply Bisection Method
    double rootBisection = bisectionMethod(p0, p1, maxIter);
    printf("Bisection Method Root: %.10f\n", rootBisection);

    // Apply False Position Method
    double rootFalsePosition = falsePositionMethod(p0, p1, maxIter);
    printf("False Position Method Root: %.10f\n", rootFalsePosition);

    // Apply Secant Method
    double rootSecant = secantMethod(p0, p1, maxIter);
    printf("Secant Method Root: %.10f\n", rootSecant);

    //Output:
    /*
    
    Bisection Method Root: 0.4476562500
    False Position Method Root: 0.4441206618
    Secant Method Root: -3024.2620795773
    
    */

    return 0;
}
