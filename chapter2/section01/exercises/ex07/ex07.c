/* 
    Created by Jonas H. Melo 07/16/2024.
    This file is licensced under MIT license.
    
    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find the first positive value of x that satisfies
    x = 2sin(x) within 0.00001 of accuracy.
*/

#include<stdio.h>
#include<math.h>

// Implementing the function 2*sin(x)
double f(double x){
    return x - 2*sin(x);
}

int main(){
    double interval[2] = {1,5};
    double tolerance = pow(10,-5);
    double a = interval[0];
    double FA = f(a);
    double b = interval[1];
    
    int maxIteractions = 50;
    int i = 1;
    while(i <= maxIteractions ){
        double p = a + (b-a)/2;
        double FP = f(p);

        if(FP == 0 || (b-a) / 2 < tolerance){
            printf("Procedure executed successfully with %d iteractions\n",i);
            printf("First positive value of x that satisfies x = 2sin(x).: %.5f\n",p);
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

    return 0;
}
