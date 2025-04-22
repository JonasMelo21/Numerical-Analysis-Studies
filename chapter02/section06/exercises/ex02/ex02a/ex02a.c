/*
    Created by Jonas H. Melo on 2025/03/27
    This file is protected under the MIT license.

    This code is part of my studies in numerical analysis,
    following Section 6 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach:
    This code aims to implement the Newton Method to find the solution for
    f(x) =  x^4 + 5x^3 - 9x^2 - 85x - 136
*/

#include <math.h>
#include <stdio.h>

double f(double x){
    return pow(x,4) + 5 * pow(x,3) - 9 * pow(x,2) - 85*x - 136;
}

double derivative(double x){
    return 4*pow(x,3) + 15*pow(x,2) - 18*x - 85;
}

double newtonMethod(double p0, double tolerance, int maxIteractions){
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = p0 - (f(p0)) / (derivative(p0));
        if(fabs(p - p0) < tolerance){
            printf("\nNewton Method Executed Successfully after %d iteractions",i);
            return p;
        }
        p0 = p;
        i++;
    }

    printf("\nNewton Method failed after %d iteractions",i);
    return -1;
}

int main(){
    double tolerance = pow(10,-4); // alternative: 0.0001
    double p0 = -2;
    int maxIteractions = 50;
    double solution = newtonMethod(p0,tolerance,maxIteractions);
    if(solution == -1){}
    else{
        printf("\nRoot of the equation for p0 = %.5f: %.5f\n",p0,solution);
    }

    p0 = 6;
    solution = newtonMethod(p0,tolerance,maxIteractions);
    if(solution == -1){}
    else{
        printf("\nRoot of the equation for p0 = %.5f: %.5f\n",p0,solution);
    }


    return 0;
}