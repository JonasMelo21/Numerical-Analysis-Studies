/*
    Created by Jonas H. Melo on 2024/09/30
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Newton's method to find root of  the equation f(x) = x − 0.8 − 0.2 sin x = 0  with [0, π/2] with 4 digits of accuracy.
*/

#include<stdio.h>
#include<math.h>

#define PI M_PI

double f(double x){
    return x - 0.8 -0.2*sin(x);
}

double derivative_f(double x){
    return 1 -0.2*cos(x);
}

int main(){
    double p0 = 0;
    double tolerance = pow(10,-4);
    double p;
    int i = 1;
    int maxIteractions = 50;
    while(i <= maxIteractions){
        p = p0 - ((f(p0)) / (derivative_f(p0)));
        if(fabs(p - p0) < tolerance){
            printf("Method executed successfully after %d iteractions",i);
            printf("Root: %.5f",p);
            break;
        }
        p0 = p;
        i++;
    }
    if(i > maxIteractions){printf("Method failed after %d iteractions",i);
    printf("Approximation found so far: %.5f",p);
    }    
    return  0;
}