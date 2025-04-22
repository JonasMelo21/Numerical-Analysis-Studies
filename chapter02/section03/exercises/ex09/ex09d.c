/*
    Created by Jonas H. Melo on 2024/11/3
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're going to use the False Position method with an accuracy of 5 digits 
    to find solutions for the equation x − 0.8 − 0.2*sin(x) = 0 within the interval [0, π/2].
*/

#include <math.h>
#include <stdio.h>

// Define the function f(x) = x - 0.8 - 0.2*sin(x)
double f(double x) {
    return x - 0.8 - 0.2 * sin(x);
}

// Implement the False Position Method
// Parameters:
// - p0 and p1: initial endpoints of the interval
// - tol: tolerance for the desired accuracy
// - maxIteractions: maximum number of iterations allowed
double falsePosition(double p0, double p1, double tol, int maxIteractions) {
    double p;       // Variable to store the current approximation of the root
    int i = 2;      // Iteration counter, starting from the 2nd iteration

    // Start the iteration loop up to the maximum number of iterations
    while (i <= maxIteractions) {
        // Calculate the next approximation using the False Position formula
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));

        // Check if the result meets the tolerance criteria
        if (fabs(p - p1) < tol) {
            printf("Solution found after %d iterations\n", i);
            return p;   // Return the solution if within tolerance
        }

        // Update the interval based on the sign of f(p)
        if (f(p) * f(p1) < 0) {
            p0 = p1;    // Set p0 to the previous endpoint if sign changes
        }
        p1 = p;        // Update p1 to the new approximation
        i++;           // Increment the iteration count
    }
    return -1;          // Return -1 if no solution was found within max iterations
}

int main() {
    double p0 = 0,            // Starting point of the interval
           p1 = M_PI / 2,     // Ending point of the interval (π/2)
           tol = pow(10, -5); // Tolerance for 5 decimal places of accuracy
    int maxIteractions = 50;  // Maximum number of iterations allowed

    // Call the False Position method to find the root
    double result = falsePosition(p0, p1, tol, maxIteractions);

    // Check if the method succeeded and print the result
    if (result == -1) {
        printf("Method failed after %d iterations\n", maxIteractions);
    } else {
        printf("The root for the equation x - 0.8 - 0.2*sin(x) = 0 within [0, π/2] is %.5lf\n", result);
    }
    return 0;
}
