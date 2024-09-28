/*
    Created by Jonas H. Melo on 2024/09/28
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Newton's method to find p2 for the equation f(x) = x^2 - 6 with p0 = 1 .
*/

#include<stdio.h>
#include<math.h>


double f(double x){
    return pow(x,2) - 6;
}

double derivative(double x){
    return 2*x;
}

int main(){
    int i = 1;
    double p;
    double p0 = 1;
    while(i <= 2){
        p = p0 - f(p0) / derivative(p0);
        p0 = p;
        i++;
    }
    printf("p2 = %.5lf\n", p);
    return 0;
}