/*
    Created by Jonas H. Melo on 2024/11/4
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use False Position Method with 5 digits of accuracy 
    to find solutions for for sin(x) - exp(-x) = 0 
    for 0 ≤ x ≤ 1, 3 ≤ x ≤ 4 and 6 ≤ x ≤ 7

*/

#include <stdio.h>
#include <math.h>

// Define the function f(x) = ln(x - 1) + cos(x - 1)
double f(double x) {
    return sin(x) - exp(-x);
}

// Implement the False Position Method
// Parameters:
// - p0 and p1: initial points for the interval
// - tolerance: required accuracy for the solution
// - maxIteractions: maximum number of iterations allowed
double falsePosition(double p0, double p1, double tolerance, int maxIteractions) {
    // Check if there's a root in the interval [p0, p1] by confirming f(p0) * f(p1) < 0
    if (f(p0) * f(p1) > 0) {
        printf("\nF(%.lf) = %.3f and F(%.3f) = %.lf\n",p0,f(p0),p1,f(p1));
        printf("F(%lf) * F(%lf) > 0, so the False Position method is not suitable for this problem\n", p0, p1);
        return -1; // Exit if the method is not suitable
    } else {
        double p;   // Variable to store the current approximation of the root
        int i = 2;  // Iteration counter

        // Start the iteration loop until the maximum number of iterations is reached
        while (i <= maxIteractions) {
            // Compute the new approximation using the False Position formula
            p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));

            // Check if the solution meets the tolerance criteria
            if (fabs(p - p1) < tolerance) {
                return p;   // Return the root if tolerance is met
            }

            // Update the interval for the next iteration based on the sign of f(p)
            if (f(p) * f(p1) < 0) {
                p0 = p1;
            }
            p1 = p;
            i++;  // Increment the iteration count
        }
        return -1;  // Return -1 if no solution was found within max iterations
    }
}

int main() {
    int max = 50;          // Maximum number of iterations allowed
    double tol = pow(10, -5);  // Tolerance set to 5 decimal places of accuracy
    double p0 = 0;        // Start of the interval
    double p1 = 1;        // End of the interval
    double solution = falsePosition(p0, p1, tol, max);

    // Check if the solution was found and display it
    if (solution != -1) {
        printf("\nSolution for sin(x) - exp(-x) = 0 within [%.lf, %.lf] is %lf",p0,p1, solution);
    } else {
        // Print failure message if the method did not converge
        printf("The method did not converge\n");
    }

    // Next interval [3,4]
    double a0 = 3;        // Start of the interval
    double a1 = 4;        // End of the interval
    double solution2 = falsePosition(a0, a1, tol, max);

    // Check if the solution was found and display it
    if (solution2 != -1) {
        printf("\nSolution for sin(x) - exp(-x) = 0 within [%.lf, %.lf] is %lf",a0,a1, solution2);
    } else {
        // Print failure message if the method did not converge
        printf("\nThe method did not converge\n\n");
    }

    double b0 = 6;        // Start of the interval
    double b1 = 7;        // End of the interval
    double solution3 = falsePosition(b0, b1, tol, max);

    // Check if the solution was found and display it
    if (solution3 != -1) {
        printf("\nSolution for sin(x) - exp(-x) = 0 within [%.lf, %.lf] is %lf",b0,b1, solution3);
    } else {
        // Print failure message if the method did not converge
        printf("\nThe method did not converge\n\n");
    }
    return 0;
}
