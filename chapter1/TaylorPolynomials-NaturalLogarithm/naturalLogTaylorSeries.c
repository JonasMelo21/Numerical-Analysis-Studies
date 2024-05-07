/*
   Created by Jonas H. Melo on 05/06/2024
   This code is licensed under MIT license
   
   This code is part of my studies in numerical analysis,
   following Section 3 of Chapter 1 in the book "Numerical Analysis"
   by Richard L. Burden and J. Douglas Faires, 11th edition.


   Book: Numerical Analysis
   Authors: Richard L. Burden, J. Douglas Faires
   Edition: 11th
   Chapter: 1, Section 3

   As explained in the README of this project
   This code aims to compute the value of N
   Such that the Nth term of the Taylor Polynomial
   is less than 0.00001

*/

#include <stdio.h>

int naturalLogTaylorApproximation(double x, double tolerance, int maxIterations) {
    int n = 1;              //The n-th term of the polynomial
    double y = x - 1;       // The factor (x - 1) in the Taylor Polynomial
    int sign = -1;          // The factor (-1) in the Taylor Polynomial
    double sum = 0;         // The result of the series sum
    double power = y;
    double term = y;

    while (n <= maxIterations) {
        sign = -sign;
        sum = sum + (sign * term);
        power = power * y;
        term = power / (n + 1);
        n = n + 1;
    }
    if( term < tolerance){
        return n;
    }
    if (n > maxIterations) {
        return -1;
    }

    return n;
}

int main() {
    double x = 1.5;                // Calculate log(x) for x = 1.5
    double tolerance = 0.00001;    // The difference between actual and numerical calculated value is 0.00001
    int maxIteractions = 15;        // Maximum number of iteractions
    int result = naturalLogTaylorApproximation(x,tolerance,maxIteractions);
    printf("\n%d iteractions required to compute Taylor Polynomial for log(x)",result);
    return 0;
}
