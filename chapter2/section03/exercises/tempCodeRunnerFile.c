/*
    Created by Jonas H. Melo on 2024/10/05
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use 5 digits of accuracy 
    to find solutions for sin(x) − e^−x = 0 
    for 0 <= x <= 1, 3 <= x <= 4 and 6 <= x <= 7

    Obs: e = 2.71828...
*/

#include<math.h>
#include<stdio.h>
#define e M_E

double f(double x){
    return sin(x) - pow(e,-x);
}

double derivative_f(double x){
    return cos(x) + pow(e,x);
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
    double solution1 = newtonMethod(0,50,pow(10,-5));
    if(solution1 != -1){
        printf("\nSolution for sin(x) - e^-x = 0 for 0 <= x <= 1: %.5f\n",solution1);
    }

    double solution2 = newtonMethod(4,50,pow(10,-5));
    if(solution1 != -1){
        printf("Solution for sin(x) - e^-x = 0 for 3 <= x <= 4: %.5f\n",solution2);
    }

    double solution3 = newtonMethod(7,50,pow(10,-5));
    if(solution1 != -1){
        printf("Solution for sin(x) - e^-x = 0 for 6 <= x <= 7: %.5f\n",solution3);
    }

    return 0;
}