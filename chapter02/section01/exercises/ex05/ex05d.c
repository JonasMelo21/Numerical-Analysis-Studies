/* 
    Created by Jonas H. Melo 07/10/2024.
    This file is licensced under MIT license.
    
    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find the root of the equation x*cos x − 2x^2 + 3x − 1 = 0 on the intervals {0.2,0.3} and {1.2,1.3}
*/

#include<math.h>
#include<stdio.h>

// Implementing the function x*cos x − 2x^2 + 3x − 1 
double f(double x){
    return x*cos(x) - 2*pow(x,2) + 3*x - 1;
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
    double interval1[2] = {0.2,0.3};
    double interval2[2] = {1.2,1.3};
    double tol = pow(10,-5);

    double x1 = bisectionMethod(interval1,tol,30,f);
    printf("\nSolution for the equation xcos(x) - 2x^2 +3x -1 on {0.2,0.3}: %.5f\n",x1);

    double x2 = bisectionMethod(interval2,tol,30,f);
    printf("\nSolution for the equation xcos(x) - 2x^2 +3x -1 = 0 on {1.2,1.3}: %.5f\n",x2);
    return 0;
}