/* 
    Created by Jonas H. Melo 07/12/2024.
    This file is licensced under MIT license.
    
    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find the root of the equation 3x - e^x.
    on [1,2]
*/

#include<math.h>
#include<stdio.h>

// Implementing the function 3x - e^x
double f(double x){
    return 3*x - pow(M_E,x);
}

double bisectionMethod(double interval[2], double tol, int maxIteractions,double(*func)(double)){
    double a = interval[0];
    double b = interval[1];
    double FA = func(a);
    
    // F(a) and F(b) must have opposite signs
    if(FA * f(b) > 0){
        printf("\nThe values of the function for the endpoints a and b must have oppposite signs\n");
        return -1;
    }
    int i = 1;
    while(i < maxIteractions){

        // Initializing the midpoint between of the endpoints a and b
        double p = a + (b - a)/2;
        double FP = func(p);

        // Procedure completed successfully
        if(FP == 0 || (b - a)/2 < tol){
            return p;
        }

        // The value of p such that F(p) = 0 is between p and b, so the new interval for the search is [p,b]
        if(FA * FP > 0){
            a = p;
            FA = FP;
        }
        // The value of p such that F(p) = 0 is between a and p, so the new interval is [a,p]
        else{
            b = p;
        }
        i++;
    }
    printf("Procedure failure after %d iteractions",i);
}

int main(){
    double interval[2] = {1,2};
    double tol = pow(10,-5);
    double solution = bisectionMethod(interval,tol,30,f);
    printf("\nSolution for the equation 3x - e^x = 0 on [1,2]: %.5f\n",solution);
    return 0;
}