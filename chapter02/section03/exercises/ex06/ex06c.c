/*
    Created by Jonas H. Melo on 2024/10/05
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use 5 digits of accuracy 
    to find solutions for 2*x*cos(2x) − (x − 2)^2 = 0
    for  2 ≤ x ≤ 3 and 3 ≤ x ≤ 4
*/

#include <stdio.h>
#include <math.h>

double f(double x){
    return 2*x*cos(2*x) - pow(x-2,2);
}

double derivative_f(double x){
    return 2*cos(2*x) - 4*x*sin(2*x) -2*(x - 2);
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

    double solution1 = newtonMethod(2,50,pow(10,-5));
    printf("Solution for 2*x*cos(2x) - (x - 2)^2 = 0 for 2 ≤ x ≤ 3: %.5f\n",solution1);

    double solution2 = newtonMethod(4,50,pow(10,-5));
    printf("Solution for 2*x*cos(2x) - (x - 2)^2 = 0 for 3 ≤ x ≤ 4: %.5f\n",solution2);

    return 0;
}