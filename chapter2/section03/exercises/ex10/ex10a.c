/*
    Created by Jonas H. Melo on 2024/11/04
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use False Position Method with 5 digits of accuracy 
    to find solutions for e^x + 2^−x + 2*cos x − 6 = 0 
    within 1 ≤ x ≤ 2
*/

#include<math.h>
#include<stdio.h>

// Define the function f(x) = x^3 - 2x^2 - 5
double f(double x){
    return exp(x) + pow(2,-x) + 2*cos(x) - 6;
}


// Implementation of the False Position Method
double falsePosition(double p0, double p1, double tol, int maxIteractions){
    
    // Checking if the root is bounded by P0 and P1
    if(f(p0) * f(p1) > 0){
        printf("As F(%.lf) * F(%.lf), %.lf and %.lf doesn't have opposite signs. So the false position method is not applicable\n");
        return -1;
    }


    else{
        double p;
        int i = 2;
        while(i <= maxIteractions){

            // Computing pn just like secant method
            p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
            if(fabs(p - p1) < tol){
                printf("Method executed successfully after %d iteractions\n",i);
                return p;
            }

            // Checking if P and P1 bound the root. If not, the next iteraction will be between P0 and P
            else if(f(p) * f(p1) < 0){
                p0 = p1;
            }
            p1 = p;
            i++;
        }
        if(i > maxIteractions){
            return -1;
        }
    }
    
}

int main(){

    // Defining parameters for the False Position method
    double tol = pow(10,-5);
    int max = 50;
    double p0 = 1;
    double p1 = 2;
    double solution = falsePosition(p0,p1,tol,max);


    if(solution != -1){
        printf("Solution for e^x + 2^-x + 2*cos x - 6 = 0 within [1,2]: %.5f",solution);
    }
    else{
        printf("Method failed");
    }

    return 0;
}