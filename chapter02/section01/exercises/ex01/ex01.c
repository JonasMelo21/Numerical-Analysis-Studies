/*
    Created by Jonas H. Melo on 07/01/2024
    This code is protected under MIT license
    
    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    The following code aims to find the P3 for the function...
    F(x) = x^(1/2) - cos(x)  on [0,1]
*/

#include <stdio.h>
#include <math.h>

// Function whose root will be found
double f(double x){
    return sqrt(x) - cos(x);
}

int main(){
    // Initializing variables for the interval [0,1]
    double a = 0;
    double b = 1;
    double p;
    double FA = f(a);

    for(int i = 1; i <= 3; i++){
        p = (a + b) / 2;
        double FP = f(p);

        // Print the values for debugging
        printf("Iteration %d:\n", i);
        printf("a = %.7f, FA = %.7f\n", a, FA);
        printf("b = %.7f, f(b) = %.7f\n", b, f(b));
        printf("p = %.7f, FP = %.7f\n", p, FP);

        if(FA * FP > 0){
            a = p;
            FA = FP;
        } else {
            b = p;
        }
    }

    printf("The value found by the bisection method after 3 iterations is: %.7f\n", p);

    return 0;
}
