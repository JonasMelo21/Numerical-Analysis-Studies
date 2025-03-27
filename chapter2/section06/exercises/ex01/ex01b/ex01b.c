/*
    Created by Jonas H. Melo on 2025/03/24
    This file is protected under the MIT license.

    This code is part of my studies in numerical analysis,
    following Section 6 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach:
    This programm aims to compute the root of the equation below by Newton Method
    f(x) = x^3 + 3x^2 - 1 
    With 4 digits of tolerance
*/

#include <math.h>
#include <stdio.h>

double f(double x){
    return pow(x,3) + 3 * pow(x,2) - 1;
}

double derivative(double x){
    return 3 * pow(x,2) + 6 * x;
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
    double p0 = 1;
    int maxIteractions = 50;
    double solution = newtonMethod(p0,tolerance,maxIteractions);
    if(solution == -1){}
    else{
        printf("\nRoot of the equation between 0 and 1: %.5f\n",solution);
    }

    p0 = 0 - 1;
    solution = newtonMethod(p0,tolerance,maxIteractions);
    if(solution != -1){
        printf("\nRoot of the equation between 0 and -1: %.5f\n",solution);
    }else{
        printf("\nNewton method failed for p0 = %.5f\n",p0);
    }

    /*
    Newton Method Executed Successfully after 5 iteractions
    Root of the equation between 0 and 1: 0.53209

    Newton Method Executed Successfully after 3 iteractions
    Root of the equation between 0 and -1: -0.65270
    */

    return 0;
}