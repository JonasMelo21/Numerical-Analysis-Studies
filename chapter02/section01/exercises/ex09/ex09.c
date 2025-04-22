/* 
    Created by Jonas H. Melo 07/28/2024.
    This file is licensced under MIT license.
    
    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find the first positive value of x that satisfies
    exp(x) - 2 = cos(exp(x) - 2) within 0.00001 of accuracy.
*/
#include<math.h>
#include<stdio.h>

double f(double x){
    return exp(x) - 2 - cos(exp(x) - 2);
}

int main(){
    double a = 0.5;
    double b = 1.5;
    double tol = pow(10,-5);
    double FA = f(a);
    int i = 1;
    int maxIteractions = 50;
    double p;

    while(i <= maxIteractions){
        p = a + (b - a)/2;
        double FP = f(p);

        if(FP == 0 || (b - a)/2 < tol){
            printf("Procedure executed successfully after %d iteractions.\n",i);
            printf("Value of p that satisfies e^p - 2 = cos(e^p - 2): %.5f",p);
            break;
        }
        else if(FA * FP > 0){
            a = p;
            FA = FP;
        }
        else{
            b = p;
        }
        i++;
    }

    if(i > maxIteractions){
        printf("Procedure failed after %d iteractions.\n");
        printf("Current value of P: %.5f\n",p);
    }

    return 0;
}