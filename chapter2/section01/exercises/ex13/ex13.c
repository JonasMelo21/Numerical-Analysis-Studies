/*
    Created by Jonas H. Melo on 2024/08/08
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We need to find an approximation to 25^(1/3) = 5^(2/3) within 0.0001 digits of accuracy.
*/

#include <stdio.h>
#include<math.h>

double f(double x){
    return x - pow(5,2.0/3.0);
}

int main(){
    double tol = pow(10,-4);
    double a = 0;
    double b = 5;
    double FA = f(a);
    double p;
    double FP;
    int i = 1;
    while(i <= 50){
        p = a + (b - a)/2;
        FP = f(p);
        if(FP == 0 || (b - a) < tol){
            printf("\nProcedure executed successfully after %d iteractions",i);
            printf("Approximated value of 25^(1/3): %.4f",p);
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
    if(i >= 50){
        printf("Procedure failed after %d iteractions",i);
        printf("Value of p so far: %.4f",p);
    }


    return 0;
}