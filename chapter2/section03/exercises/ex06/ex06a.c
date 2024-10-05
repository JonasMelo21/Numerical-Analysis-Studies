/*
    Created by Jonas H. Melo on 2024/10/01
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use 5 digits of accuracy 
    to find solutions for e^x + 2^−x + 2*cos x − 6 = 0 
    for 1 ≤ x ≤ 2
*/

#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(x) + pow(2,-x) + 2*cos(x) - 6;
}

double derivative_f(double x){
    return exp(x) - pow(2,-x)*log(2) - 2*sin(x);
}

int main(){
    double p0 = 1;
    double p;
    int i = 1;
    int maxIteractions = 50;
    double tolerance = pow(10,-5);
    while(i <= maxIteractions){
        p = p0 - ((f(p0)) / (derivative_f(p0)));
        if(fabs(p - p0) < tolerance){
            printf("\nMethod executed successfully after %d iteractions\n",i);
            printf("Value of P found: %.5f\n",p);
            break;
        }
        p0 = p;
        i++;
    }
    if(i > maxIteractions){
    printf("Method failed after %d iteractions\n");}
    return 0;
}