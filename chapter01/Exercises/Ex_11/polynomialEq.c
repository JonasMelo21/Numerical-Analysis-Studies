/*
Created by Jonas H. Melo on 22/06/2024
This code is licensed under MIT license

This code is part of my studies in numerical analysis,
following Section 3 of Chapter 1 in the book "Numerical Analysis"
by Richard L. Burden and J. Douglas Faires, 11th edition.

Book: Numerical Analysis
Authors: Richard L. Burden, J. Douglas Faires
Edition: 11th
Chapter: 1, Section 3

The following code aims to solve the exercise presented in README file
Which is:
Compute (x - xo)(x - x1)(x - x2)...(x - xn) 
Given by the user a number n of terms, the terms x1,...,xn 
And the value of X
*/

#include <stdio.h>

double calculatePolynomial(int num_terms, double x) {
    double result = 1;
    double term;
    for (int i = 1; i <= num_terms; i++) {
        printf("Type the term at position %d: ", i);
        scanf("%lf", &term);  // Use %lf for reading double
        result *= (x - term);
    }
    return result;
}

int main() {
    int n;
    double x;
    printf("Type the number of terms of the polynomial: ");
    scanf("%d", &n);  // Use %d for reading integer
    printf("Type the value of x: ");
    scanf("%lf", &x);  // Use %lf for reading double

    double solution = calculatePolynomial(n, x);
    printf("Solution: %f\n", solution);

    return 0;  // Return statement for main function
}