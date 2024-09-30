/*
    Created by Jonas H. Melo on 2024/09/30
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Newton's method to find root of  the equation f(x) = x^3 - 2x^2 -5 = 0  with [1,4] with 4 digits of accuracy.
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x,3) - 2*pow(x,2) - 5;
}

double derivative_f(double x){
    return 3*pow(x,2) - 4*x;
}


int main(){
    double TOL = pow(10,-4);
    double p0 = 1;
    double p;
    int i = 1;
    int maxIteractions = 50;
    while(i <= maxIteractions){
        p = p0 - f(p0) / derivative_f(p0);
        if(fabs(p - p0) < TOL){
            printf("\nMethod executed successfully after %d iteractions\n",i);
            printf("Root of the equation: %.5f\n",p);
            break;
        }
        p0 = p;
        i++;
    }
    if(i > maxIteractions){
    printf("Method failed after %d iteractions\n",i);
    }
    return 0;
}