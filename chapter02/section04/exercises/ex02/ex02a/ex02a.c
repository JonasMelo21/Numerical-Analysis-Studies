/*
    Created by Jonas H. Melo on 2025/01/13
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 4 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: 
    The question title tells us to use Newton Method to find the solution for
        1 − 4x*(cos x) + 2x^2 + cos(2x) = 0, 
    For 0 ≤ x ≤ 1 
    But we're gnna go further and compare the performance of all root finding methods studied so far, which are:
    -   Traditional Newton Method
    -   Bisection Method
    -   Secant Method
    -   False Position Method
    -   Modified Newton Method

*/
#include<math.h>
#include<stdio.h>

//  Function
double f(double x){
    return 1 - 4*x*cos(x) + 2*pow(x,2) + cos(2*x);
}

// First Derivative
double derivative(double x) {
    return 4*cos(x) - 4*x*sin(x) + 4*x -2*sin(2*x);
}

// Second Derivative for Modified Newton Method
double secondDerivative(double x) {
    return -8*sin(2*x) - 4*x*cos(x) + 4 -2*cos(2*x);
}


// Newton's method
double newtonMethod(double p0,double tolerance, int maxIteractions){
    double a0 = p0;
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = a0 - (f(a0)) / (derivative(a0));
        if( fabs(p - a0) < tolerance || f(p) == 0){
            printf("\nTraditional Newton Method Success (%d iteractions)",i);
            return p;
        }
        a0 = p;
        i++;
    }
    return -1;
}

double modifiedNewton(double p0, double tolerance, int maxIterations) {
    double a0 = p0;    // Initial guess
    double p;          // Next approximation
    int i = 1;         // Iteration counter

    while (i <= maxIterations) {
        // Calculate the numerator and denominator separately
        double numerator = f(a0) * derivative(a0);
        double denominator = pow(derivative(a0), 2) - f(a0) * secondDerivative(a0);

        // Check if the denominator is too small to avoid division by zero
        if (fabs(denominator) < 1e-10) {
            printf("\nModified Newton Method failed: denominator too small at iteration %d for p0 = %.5f.\n", i, p0);
            return -1; // Fail
        }

        // Calculate the next approximation
        p = a0 - (numerator / denominator);

        // Check convergence
        if (fabs(p - a0) < tolerance || fabs(f(p)) < tolerance) {
            printf("\nModified Newton Method Success (%d iterations): p0 = %.5f\n", i, p0);
            return p;
        }

        // Update for the next iteration
        a0 = p;
        i++;
    }

    // If maximum iterations are reached without convergence
    printf("\nModified Newton Method failed.\n", maxIterations, p0);
    return -1; // Fail
}

// Secant method
double secantMethod(double p0, double p1, double tolerance, int maxIteractions){
    double a0 = p0, a1 = p1, p;
    int i = 2;

    while(i <= maxIteractions){
        p = a1 - (f(a1) * (a1 - a0)) / (f(a1) - f(a0)); // Secant formula
        if(fabs(p - a1) < tolerance || f(p) == 0){ // Convergence check
            printf("\nSecant Method Success (%d iterations): p0 = %.5f, p1 = %.5f\n", i, p0, p1);
            return p;
        }
        a0 = a1; // Shift points
        a1 = p;
        i++;
    }
    return -1; // Fail
}

// False position method
double falsePosition(double p0, double p1, double tolerance, int maxIteractions){
    double a0 = p0, a1 = p1, p;
    int i = 1;

    while(i <= maxIteractions){
        p = a1 - (f(a1) * (a1 - a0)) / (f(a1) - f(a0)); // False position formula
        if(fabs(p - a1) < tolerance || f(p) == 0){ // Convergence check
            printf("\nFalse Position Success (%d iterations): p0 = %.5f, p1 = %.5f\n", i, p0, p1);
            return p;
        }
        if(f(a0) * f(p) < 0) a1 = p; // Update interval
        else a0 = p;
        i++;
    }
    return -1; // Fail
}

// Bisection method
double bisectionMethod(double a, double b, double tolerance, int maxIteractions){
    if(f(a) * f(b) > 0){ // Initial interval validation
        printf("\nBisection Method not applicable for [%.2f, %.2f]\n", a, b);
        return -1;
    }

    double a0 = a, b0 = b, p;
    int i = 1;

    while(i <= maxIteractions){
        p = (a0 + b0) / 2; // Midpoint
        if(f(p) == 0 || (b0 - a0) < tolerance){ // Convergence check
            printf("\nBisection Method Success (%d iterations): Interval [%.5f, %.5f]\n", i, a, b);
            return p;
        }
        if(f(a0) * f(p) < 0) b0 = p; // Update interval
        else a0 = p;
        i++;
    }
    return -1; // Fail
}

int main(){
    double tolerance = pow(10, -5);
    int maxIteractions = 50;
    double p0 = 0, p1 = 1;

    // Test Newton's method
    double newtonSolution = newtonMethod(p0,tolerance, maxIteractions);
    if(newtonSolution != -1){
        printf("\nNewton Method Solution: %.5f\n", newtonSolution);
    }else{
        printf("\nTraditional Newton Method Failed\n");
    }
    // Test Secant method
    double secantSolution = secantMethod(p0, p1, tolerance, maxIteractions);
    if(secantSolution != -1) printf("Secant Method Solution: %.5f\n", secantSolution);

    // Test False Position method
    double falsePositionSolution = falsePosition(p0, p1, tolerance, maxIteractions);
    if(falsePositionSolution != -1) printf("False Position Solution: %.5f\n", falsePositionSolution);else printf("\nFalse Position Method Failed");

    // Test Bisection method
    double bisectionSolution = bisectionMethod(p0, p1, tolerance, maxIteractions);
    if(bisectionSolution != -1) printf("Bisection Solution: %.5f\n", bisectionSolution);

    // Test Modified Newton Method
    double modifiedNewtonSolution = modifiedNewton(p0,tolerance,maxIteractions);
    if(!(modifiedNewtonSolution == -1)){
        printf("Modified Newton Method Solution: %.5f");
    }

    /*Output
    Traditional Newton Method Failed

    Secant Method Success (23 iterations): p0 = 0.00000, p1 = 1.00000
    Secant Method Solution: 0.73910

    False Position Method Failed
    Bisection Method not applicable for [0.00, 1.00]

    Modified Newton Method failed.
    */

    return 0;
}
