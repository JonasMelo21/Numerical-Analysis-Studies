/*
    Created by Jonas H. Melo on 2024/11/3
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're going to use the False Position method with an accuracy of 5 digits 
    to find solutions for the equation x^3 − 2x^2 − 5 = 0 within the interval [1, 4].
*/

#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 2x^2 - 5
double f(double x) {
    return pow(x, 3) - 2 * pow(x, 2) - 5;
}

// Implement the False Position Method
// Parameters:
// - p0 and p1: initial points for the interval
// - tolerance: required accuracy for the solution
// - maxIteractions: maximum number of iterations allowed
double falsePosition(double p0, double p1, double tolerance, int maxIteractions) {
    // Check if there's a root in the interval [p0, p1] by confirming f(p0) * f(p1) < 0
    if (f(p0) * f(p1) > 0) {
        printf("F(%lf) * F(%lf) > 0, so the False Position method is not suitable for this problem", p0, p1);
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
    double p0 = 1;         // Start of the interval
    double p1 = 4;         // End of the interval
    double solution = falsePosition(p0, p1, tol, max);

    // Check if the solution was found and display it
    if (solution != -1) {
        printf("\nSolution for x^3 - 2x^2 - 5 = 0 within [1, 4] is %lf", solution);
    } else {
        // Print failure message if the method did not converge
        printf("\nThe method did not converge");
    }
    return 0;
}
