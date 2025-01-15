/*
    Created by Jonas H. Melo on 2025/01/13
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: 
    The question title tells us to use Modified Newton Method to find the solution for
        e^6x + 1.441*e^2x − 2.079*e^4x − 0.3330 = 0, 
    For − 1 ≤ x ≤ 0. 
    But we're gonna go further and compare the performance of all root finding methods studied so far, which are:
    -   Traditional Newton Method
    -   Bisection Method
    -   Secant Method
    -   False Position Method
    -   Modified Newton Method

*/
#include<math.h>
#include<stdio.h>

double f(double x) {
    return exp(6*x) + 1.441*exp(2*x) - 2.079*exp(4*x) - 0.3330;
}


// First Derivative
double derivative(double x){
    return 6*exp(6*x) + 2.882*exp(2*x) - 4.158*exp(4*x);
}

// Second Derivative for Modified Newton Method
double secondDerivative(double x){
    return 36*exp(6*x) + 5.764*exp(2*x) - 16.632*exp(4*x);
}

// Newton's method
double newtonMethod(double tolerance, int maxIteractions, double p0){
    double a0 = p0, p;
    int i = 1;

    while(i <= maxIteractions){
        p = a0 - (f(a0) / derivative(a0));
        if(fabs(p - a0) < tolerance || f(p) == 0){ // Convergence check
            printf("\nNewton Method Success (%d iterations): p0 = %.5f\n", i, p0);
            return p;
        }
        a0 = p;
        i++;
    }
    printf("Maximum iterations reached for Standard Newton Method. Last x = %.10f\n", p);
    return p; 
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
            printf("\nModified Newton Method Success (%d iterations) p0 = %.5f.\n", i, p0);
            return p;
        }

        // Update for the next iteration
        a0 = p;
        i++;
    }

    printf("\nMaximum iterations reached for Modified Newton Method. Last x = %.10f\n", p);
    return p; 
}

int main(){
    double tolerance = pow(10, -5);
    int maxIteractions = 25;
    double p0 = -5, p1 = 5;

    // Test Newton's method
    double newtonSolution = newtonMethod(tolerance, maxIteractions, p0);
    if(newtonSolution != -1) printf("Newton Method Solution: %.5f\n", newtonSolution);else{printf("\nNewton Method Failed\n");};

    // Test Modified Newton Method
    p0 = 0;
    p1 = 1;
    double modifiedNewtonSolution = modifiedNewton(p0,tolerance,maxIteractions);
    if(!(modifiedNewtonSolution == -1)){
        printf("Modified Newton Method Solution: %.5f");
    }

    /*Output:
        
    */
    return 0;
}
