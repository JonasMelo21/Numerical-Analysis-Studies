/*
    Created by Jonas H. Melo on 2024/11/4
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use False Position Method with 5 digits of accuracy 
    to find solutions for (x − 2)^2 − ln(x) = 0 
    for 1 ≤ x ≤ 2 and e ≤ x ≤ 4
*/

#include <stdio.h>
#include <math.h>

// Define the function f(x) = ln(x - 1) + cos(x - 1)
double f(double x) {
    return pow(x-2,2) - log(x);
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
    double p0 = 1;        // Start of the interval
    double p1 = 2;        // End of the interval
    double solution = falsePosition(p0, p1, tol, max);

    // Check if the solution was found and display it
    if (solution != -1) {
        printf("\nSolution for x^3 + 3x^2 - 1 = 0 within [%.lf, %.lf] is %lf",p0,p1, solution);
    } else {
        // Print failure message if the method did not converge
        printf("The method did not converge\n");
    }

    // Next interval [3,4]
    p0 = exp(1);        // Start of the interval
    p1 = 4;        // End of the interval
    double solution2 = falsePosition(p0, p1, tol, max);

    // Check if the solution was found and display it
    if (solution2 != -1) {
        printf("\nSolution for x^3 + 3x^2 - 1 = 0 within [e, 4] is %lf", solution2);
    } else {
        // Print failure message if the method did not converge
        printf("\nThe method did not converge\n\n");
    }
    return 0;
}
