/* 
    Created by Jonas H. Melo 07/18/2024.
    This file is licensced under MIT license.
    
    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find the first positive value of x that satisfies
    x = tan(x) within 0.00001 of accuracy.
*/

#include<stdio.h>
#include<math.h>

// Implementing the function x - tan(x) because we wanna find x - tan(x) = 0
double f(double x){
    return x - tan(x);
}

int main(){
    double tol = pow(10,-5);

    // a and b are the endpoints of the range
    double a = 1;
    double b = 2;
    double FA = f(a);
    // maximum number of iteractions because we dont wanna get into an infinite loop
    int maxIteractions = 50;
    int i;
    for(i = 1;i < maxIteractions;i++){
        double p = a + (b - a)/2;
        double FP = f(p);
        if(FP == 0 || (b - a) < tol){
            printf("Procedure executed successfully after %d iteractions\n",i);
            printf("The 1st positive value of x which x = tan(x) is :%.5f\n",p);
            break;
        }
        else if(FA * FP > 0){
            a = p;
            FA = FP;
        }
        else{
            b = p;
        }
    }
    return 0;
}