/*
    Created by Jonas H. Melo on 2024/11/2
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use Secant method with 5 digits of accuracy 
    to find solutions for sin(x) − exp(-x) = 0 for 0 ≤ x ≤ 1 and 3 ≤ x ≤ 4 and 6 ≤ x ≤ 7
*/

#include <stdio.h>
#include <math.h>

// Define the function f(x) = sin(x) - exp(-x)
double f(double x){
    return sin(x) - exp(-x);
}

// Implement the Secant Method
// Parameters:
// - p0 and p1 are initial guesses for the solution
// - tolerance is the desired accuracy
// - maxIteractions is the maximum number of iterations
double secantMethod(double p0, double p1, double tolerance, int maxIteractions) {
    double p;            // Variable to store the new approximation
    int i = 2;           // Start iteration count at 2 since two guesses are provided

    // Loop until maximum iterations are reached
    while (i < maxIteractions) {
        // Compute the new approximation using the Secant formula
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));

        // Check if the difference is within the desired tolerance
        if (fabs(p - p1) < tolerance) {
            return p;    // Solution found
        }

        // Update guesses for the next iteration
        p0 = p1;
        p1 = p;
        i++;            // Increment iteration count
    }
    return -1;           // Return -1 if no solution was found within max iterations
}

int main() {
    double a = 0;        // Interval start for first solution
    double b = 1;        // Interval end for first solution
    double tol = pow(10, -5);   // Tolerance set to 5 digits of accuracy
    int max = 50;        // Maximum number of iterations
    double solution1;

    // Solve for sin(x) - exp(-x) in the interval [0, 1] using the Secant method
    solution1 = secantMethod(a, b, tol, max);
    if (solution1 != -1) {
        // Print solution if found
        printf("\n\nSolution for sin(x) - exp(-x) = 0 for [0,1]: %.5f", solution1);
    } else {
        // Print failure message if method did not converge
        printf("\nMethod failed for sin(x) - exp(-x) = 0 for [0,1]");
    }

    double c = 3;        // Interval start for second solution
    double d = 4;        // Interval end for second solution
    double solution2;

    // Solve for sin(x) - exp(-x) in the interval [3, 4] using the Secant method
    solution2 = secantMethod(c, d, tol, max);
    if (solution2 != -1) {
        // Print solution if found
        printf("\n\nSolution for sin(x) - exp(-x) within [3,4]: %.5f", solution2);
    } else {
        // Print failure message if method did not converge
        printf("\nMethod failed for sin(x) - exp(-x) within [3,4]");
    }

    double e = 6;        // Interval start for second solution
    double f = 7;        // Interval end for second solution
    double solution3;

    // Solve for sin(x) - exp(-x) in the interval [6, 7] using the Secant method
    solution3 = secantMethod(e, f, tol, max);
    if (solution3 != -1) {
        // Print solution if found
        printf("\n\nSolution for sin(x) - exp(-x) within [6,7]: %.5f", solution3);
    } else {
        // Print failure message if method did not converge
        printf("\nMethod failed for sin(x) - exp(-x) within [6,7]");
    }

    return 0;
}
