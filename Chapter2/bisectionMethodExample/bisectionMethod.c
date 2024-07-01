/*
   Created by Jonas H. Melo on 05/06/2024
   This code is licensed under MIT license

   This code is part of my studies in numerical analysis,
   following Section 1 of Chapter 2 in the book "Numerical Analysis"
   by Richard L. Burden and J. Douglas Faires, 11th edition.

   The following code aims to find the solution "p" of the equation:
   x^3 + 4x^2 - 10 = 0

   Note: p should be accurate at least within 10^-4 = 0.0001
*/

#include <stdio.h>  // Standard library for input and output
#include <math.h>   // Math library for functions like pow()

// Function that represents the equation x^3 + 4x^2 - 10
double f(double x) {
    return pow(x, 3) + 4 * pow(x, 2) - 10;
}

// Function that calculates the root of the equation using the bisection method
double calculateRoot(double a, double b, double tolerance, int maxIterations) {
    int i = 1;           // Iteration counter
    double FA = f(a);    // Value of the function at a
    while (i < maxIterations) {  // Iteration loop up to the maximum allowed
        double p = a + ((b - a) / 2);  // Calculate the midpoint p
        double FP = f(p);  // Value of the function at p
        if (FP == 0 || (b - a) / 2 < tolerance) {  // If the root is found or the interval is within tolerance
            return p;  // Return the root
        }
        i++;  // Increment the iteration counter
        if (FA * FP > 0) {  // If f(a) and f(p) have the same sign
            a = p;  // Move the lower bound to p
            FA = FP;  // Update the function value at the new lower bound
        } else {
            b = p;  // Move the upper bound to p
        }
    }
    return (a + b) / 2; // Return the midpoint if max iterations reached
}

int main() {
    printf("\nComputing the solution for equation: x^3 + 4x^2 - 10 = 0\n");
    printf("%.4f\n", calculateRoot(1, 2, 0.0001, 15));  // Calculate and print the root
    return 0;
}
