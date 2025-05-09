/*
    Created by Jonas H. Melo on 2024/10/06
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Secant's method to find root 
    of  the equation f(x) = ln(x − 1) + cos(x − 1) = 0 
    within [1.3,2] with 4 digits of accuracy.
*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return log(x-1) + cos(x - 1);
}

int main(){
    double tolerance = pow(10,-4);
    double p0 = 1.3;
    double p1 = 2;
    double p;
    int i = 2;
    int maxIteractions = 50;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tolerance){
            printf("\nMethod executed successfully after %d iteractions",i);
            printf("\nRoot: %.5f",p);
            break;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    if(i > maxIteractions){
        printf("Method failed");
    }
    return 0;

}