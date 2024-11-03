/*
    Created by Jonas H. Melo on 2024/10/05
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use 5 digits of accuracy 
    to find solutions for (x − 2)^2 − ln(x) = 0 
    for 1 ≤ x ≤ 2 and e ≤ x ≤ 4

    Obs: e = 2.71828...
*/

#include<math.h>
#include<stdio.h>
#define e M_E

double f(double x){
    return pow(x-2,2) - log(x);
}

double derivative_f(double x){
    return  2*(x - 2) - 1/x;
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
        printf("\nSolution for (x - 2)^2 - ln(x) = 0 for 1 <= x <= 2: %.5f\n",solution1);
    }

    double solution2 = newtonMethod(4,50,pow(10,-5));
    if(solution1 != -1){
        printf("Solution for (x - 2)^2 - ln(x) = 0 for e <= x <= 4: %.5f\n",solution2);
    }
    
    return 0;
}