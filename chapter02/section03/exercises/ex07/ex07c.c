/*
    Created by Jonas H. Melo on 2024/10/23
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Secant's method to find root 
    of  the equation f(x) = x - cos(x) = 0  
    within [0, π/2] with 4 digits of accuracy.
*/

#include<stdio.h>
#include<math.h> 

double f(double x){
    return x - cos(x);
}

int main(){
    double pi = 3.14159265359;
    double p0 = 0;
    double p1 = pi / 2;
    double p;
    int i = 2;
    int maxIteractions = 50;
    double tol = pow(10,-4);
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tol){
            printf("\nMethod executed successfully after %d iteractions",i);
            printf("\nRoot: %.5f",p);
            break;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    if(i > maxIteractions){
        printf("Method failed. Root found so far: %.4f",p);
    }
    return 0;
}