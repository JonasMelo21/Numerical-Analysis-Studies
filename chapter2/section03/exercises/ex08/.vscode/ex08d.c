/*
    Created by Jonas H. Melo on 2024/11/2
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use Secant method with 5 digits of accuracy 
    to find solutions for (x − 2)^2 − ln(x) = 0 for 1 ≤ x ≤ 2 and e ≤ x ≤ 4
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x-2,2) - log(x);
}

double secantMethod(double p0, double p1, double tolerance, int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) <= tolerance){
            return p;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    return -1;
}

int main(){
    double a0 = 1;
    double a1 = 2;
    double tolerance = pow(10,-5);
    int maxIteractions = 50;

    double solution0 = secantMethod(a0,a1,tolerance,maxIteractions);
    if(solution0 != -1){
        printf("\nSolution for (x - 2)^2 - ln(x) = 0 within [1,2]: %.5f ",solution0);
    }
    else{
        printf("\nMethod failed");
    }

    
    double b0 = M_E;
    double b1 = 4;
    double solution1 = secantMethod(b0,b1,tolerance,maxIteractions);
    if(solution1 != -1){
        printf("\nSolution for (x - 2)^2 - ln(x) = 0 within [e,4]: %.5f ",solution1);
    }
    else{
        printf("\nMethod failed");
    }

    return 0;
}