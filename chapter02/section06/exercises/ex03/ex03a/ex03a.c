/*
    Created by Jonas H. Melo on 2025/03/24
    This file is protected under the MIT license.

    This code is part of my studies in numerical analysis,
    following Section 6 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach:
    This programm aims to compute the root of the equation below by Muller's Method
    f(x) = x^3 - 2x^2 - 5 
    With 4 digits of tolerance
*/

#include <math.h>
#include <stdio.h>

double f(double x){
    return pow(x,3) - 2 * pow(x,2) - 5;
}


double mullerMethod(double p0,double p1, double p2,double tolerance, int maxIteractions){
    double p;
    double h;
    double h1 = p1 - p0;
    double h2 = p2 - p1;
    double q1 = (f(p1) - f(p0)) / h1;
    double q2 = (f(p2) - f(p1)) / h2;
    double d = (q2 - q1) / (h2 + h1);
    double b;
    double g;
    int i =3;
    double e;
    while(i < maxIteractions){
        b = q2 + h2*d;
        g = sqrt(b*b - 4*f(p2)*d);
        if( (b - g) < (b + g)){
            e = b + g;
        }else{
            e = b - g;
        }
        h = -2*f(p2) / e;
        p = p2 + h;
        if(fabs(h) < tolerance){
            printf("\nMuller Method Executed Successfully after %d iteractions\n",i);
            return p;
        }

        p0 = p1;
        p1 = p2;
        p2 = p;

        h1 = p1 - p0;
        h2 = p2 - p1;
        q1 = (f(p1) - f(p0))/h1;
        q2 = (f(p2) - f(p1))/h2;
        d = (q2 - q1) / (h2 + h1);
        i++;
    }
    
}

int main(){
    double tolerance = pow(10,-4); // alternative: 0.0001
    double p0 = 1;
    double p1 = 2;
    double p2 = 3;
    int maxIteractions = 50;
    double solution = mullerMethod(p0,p1,p2,tolerance,maxIteractions);
    if(solution == -1){}
    else{
        printf("\nRoot of the equation for (p0=%.3f, p1=%.3f and p2=%.3f) -----> %.5f\n",p0,p1,p2,solution);
    }

    return 0;
}