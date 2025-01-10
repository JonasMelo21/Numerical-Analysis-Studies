/*
    Created by Jonas H. Melo on 2025/01/10 (YYYY/MM/DD)
    This file is protected under the MIT License.

    Numerical analysis program using various root-finding methods to solve:
    x^2 - 2*x*e^-x + e^-2x = 0, for 0 ≤ x ≤ 1.
*/

#include<math.h>
#include<stdio.h>

//  Function
double f(double x){
    return pow(x, 2) - 2 * x * exp(-x) + exp(-2 * x);
}

// First Derivative
double derivative(double x){
    return 2 * x - 2 * exp(-x) * (1 - x) - 2 * exp(-2 * x);
}

// Second Derivative for Modified Newton Method
double secondDerivative(double x){
    return 2 + 2 * exp(-x) * (1 - 2 * x) - 4 * exp(-2 * x);
}

// Newton's method
double newtonMethod(double tolerance, int maxIteractions, double p0){
    double a0 = p0, p;
    int i = 1;

    while(i <= maxIteractions){
        p = a0 - (f(a0) / derivative(a0));
        if(p - a0 < tolerance || f(p) == 0){ // Convergence check
            printf("\nNewton Method Success (%d iterations): p0 = %.5f\n", i, p0);
            return p;
        }
        a0 = p;
        i++;
    }
    return -1; // Fail
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
            printf("\nModified Newton Method executed successfully after %d iterations for x^2 - 2*x*e^-x + e^-2x = 0 with p0 = %.5f.\n", i, p0);
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
        if(p - a1 < tolerance || f(p) == 0){ // Convergence check
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
        if(p - a1 < tolerance || f(p) == 0){ // Convergence check
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
    double newtonSolution = newtonMethod(tolerance, maxIteractions, p0);
    if(newtonSolution != -1) printf("Newton Method Solution: %.5f\n", newtonSolution);

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
    p0 = 0;
    p1 = 1;
    double modifiedNewtonSolution = modifiedNewton(p0,tolerance,maxIteractions);
    if(!(modifiedNewtonSolution == -1)){
        printf("Modified Newton Method Solution: %.5f");
    }

    /*Output:
        Newton Method Success (17 iterations): p0 = 0.00000
        Newton Method Solution: 0.56714

        Secant Method Success (3 iterations): p0 = 0.00000, p1 = 1.00000
        Secant Method Solution: 0.85062

        False Position Success (2 iterations): p0 = 0.00000, p1 = 1.00000
        False Position Solution: 0.85062

        Bisection Method not applicable for [0.00, 1.00]

        Modified Newton Method executed successfully after 8 iterations for x^2 - 2*x*e^-x + e^-2x = 0 with p0 = 0.00000.
        Modified Newton Method Solution: 0.00000
    */
    return 0;
}
