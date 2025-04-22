/*
    Created by Jonas H. Melo on 2024/10/05
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use 5 digits of accuracy 
    to find solutions for e^x − 3x^2 = 0 
    for 0 <= x <= 1 and 3 <= x <= 5

    Obs: e = 2.71828...
*/

#include<math.h>
#include<stdio.h>
#define e M_E

double f(double x){
    return pow(e,x) - 3*pow(x,2);;
}

double derivative_f(double x){
    return pow(e,x) - 6*x;
}

double newtonMethod(double p0, int maxIteractions, double tolerance){
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = p0 - f(p0) / derivative_f(p0);
        if(fabs(p - p0) < tolerance){
            return p;
        }
        p0 = p;
        i++;
    }
    printf("Method failed after %d iteractions\n",maxIteractions);
    return -1;
}

int main(){
    double solution1 = newtonMethod(1,50,pow(10,-5));
    if(solution1 != -1){
        printf("Solution for x^3 + 3x^2 - 1 = 0 for 0 <= x <= 1: %.5f\n",solution1);
    }

    double solution2 = newtonMethod(5,50,pow(10,-5));
    if(solution1 != -1){
        printf("Solution for x^3 + 3x^2 - 1 = 0 for 3 <= x <= 5: %.5f\n",solution2);
    }
    
    return 0;
}