/*
    Created by Jonas H. Melo on 2025/01/13
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: 
    The question title tells us to use Newton Method to find the solution for
        e^6x + 3*(ln 2)^2*e^2*x - (ln 8)*e^4x - (ln 2)^3 = 0, 
    For -1 ≤ x ≤ 0, 
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
    return exp(6*x) + 3*pow(log(2),2) * exp(2*x) - (log(8)*exp(4*x)) - pow(log(2),3);
}

// First Derivative
double derivative(double x) {
    return 6*exp(6*x) + 6*pow(log(2),2)*exp(2*x) - 16*log(8)*exp(4*x);
}

// Second Derivative for Modified Newton Method
double secondDerivative(double x) {
    return 36*exp(6*x) + 12*pow(log(2),2)*exp(2*x) - 16*log(8)*exp(4*x);
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
    printf("\nModified Newton Method failed to converge within %d iterations for p0 = %.5f.\n", maxIterations, p0);
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
    int maxIteractions = 10000;
    double p0 = -1, p1 = 0;

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
    if(falsePositionSolution != -1) printf("False Position Solution: %.5f\n", falsePositionSolution);

    // Test Bisection method
    double bisectionSolution = bisectionMethod(p0, p1, tolerance, maxIteractions);
    if(bisectionSolution != -1) printf("Bisection Solution: %.5f\n", bisectionSolution);

    // Test Modified Newton Method
    double modifiedNewtonSolution = modifiedNewton(p0,tolerance,maxIteractions);
    if(!(modifiedNewtonSolution == -1)){
        printf("Modified Newton Method Solution: %.5f");
    }

    /*Output
    Traditional Newton Method Success (1507 iteractions)
    Newton Method Solution: -0.20572

    Secant Method Success (29 iterations): p0 = -1.00000, p1 = 0.00000
    Secant Method Solution: -0.18323

    False Position Success (424 iterations): p0 = -1.00000, p1 = 0.00000
    False Position Solution: -0.17411

    Bisection Method Success (18 iterations): Interval [-1.00000, 0.00000]
    Bisection Solution: -0.18326

    Modified Newton Method Success (47 iterations): p0 = -1.00000
    Modified Newton Method Solution: 0.00000
    */

    return 0;
}
