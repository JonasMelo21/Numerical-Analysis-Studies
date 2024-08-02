/*
    Created by Jonas H. Melo on 2024/08/02
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find the root for 
    f(x) = x^2 - 3
    with 4 digits of precision
*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return pow(x,2) - 3;
}

int main(){
    double tol = pow(10,-4);
    double a = 1;
    double FA = f(a);
    double b = 2;
    double p;
    double FP;
    int maxIteractions = 50;
    int i = 1;
    while(i <= maxIteractions){
        p = a + (b - a)/2;
        FP = f(p);
        if(FP == 0 || (b-a)/2 < tol){
            printf("Procedure executed successfully after %d iteractions\n",i);
            printf("Value of square root of 3: %.5f",p); // Output ---> 1.71399
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
        printf("Procedure failed after %d iteractions",i);
        printf("Value of p found so far: %.5f");
    }
    return 0;

}
