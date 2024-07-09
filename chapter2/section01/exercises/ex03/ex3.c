/*
    Created by Jonas H. Melo on 07/04/2024
    This code is licensed under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We will compute the solution for the equation
    x^3 - 7x^2 + 14x - 6 = 0 with accuracy of 0.001
    on the intervals [0,1], [1,3.2], and [3.2,4]
    by Bisection Method
*/

#include <stdio.h>
#include <math.h>


// Implementation of the function x^3 - 7x^2 + 14x - 6
double f(double x) {
    return pow(x, 3) - 7 * pow(x, 2) + 14 * x - 6;
}


// Implementation of bisection method
// The method receives as parameters: 
//     - the interval we wanna find the solution
//     - the tolerance 
//     - the maximum number of iteractions
//     - the function we wanna find its solution

double bisectionMethod(double interval[2], double tol, int maxIterations, double (*func)(double)) {
    // Initializing the endpoints of the interval
    double a = interval[0];
    double b = interval[1];

    // If F(a) and F(b) are the same sign, 
    // the bisection method won't work
    if (func(a) * func(b) > 0) {
        printf("Function values at the endpoints of the interval must have opposite signs.\n");
        return -1;
    }


    int i = 1;
    double FA = func(a);

    while (i <= maxIterations) {

        // Initializing the midpoint between the endpoints
        double p = a + (b - a) / 2;
        double FP = func(p);

        // Procedure completed sucessfully
        if (FP == 0 || (b - a) / 2 < tol) {
            return p;
        }

        i++;

        // Getting the correct half of the interval for next iteraction
        if (FP * FA > 0) {  
            // F(p) and F(a) has the same sign
            a = p;
            FA = FP;
        } else {
            b = p;
        }
    }

    printf("Method failed after %d iterations\n", maxIterations);
    return -1;
}

int main() {

    // Initializing the intervals we're gonna test the method
    double interval1[2] = {0, 1};
    double interval2[2] = {1, 3.2};
    double interval3[2] = {3.2, 4};
    double tol = 0.01;

    double x1 = bisectionMethod(interval1, tol, 10, f);
    printf("\nSolution on the interval [0,1]: %.2f", x1);

    double x2 = bisectionMethod(interval2, tol, 10, f);
    printf("\nSolution on the interval [1,3.2]: %.2f", x2);

    double x3 = bisectionMethod(interval3, tol, 10, f);
    printf("\nSolution on the interval [3.2,4]: %.2f", x3);

    return 0;
}
