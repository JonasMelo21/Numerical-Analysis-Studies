/*
    Created by Jonas H. Melo on 2024/09/30
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Newton's method to find root of  the equation f(x) = x^3 - 3x^2 -1 = 0  with [-3,-2] with 4 digits of accuracy.
*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return pow(x,3) + 3*pow(x,2) - 1;
}

double derivative_f(double x){
    return 3*pow(x,2) + 6*x;
}

int main(){
    double p0 = -3;
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