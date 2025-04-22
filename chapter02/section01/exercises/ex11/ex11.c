/*
    Created by Jonas H. Melo on 2024/08/01
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We'll use bisection method to find which root for
    f(x) = (x + 2)*(x + 1)^2*x*(x − 1)^3*(x − 2)
    is found in the intervals 
        [−3, 2.5],
        [−2.5, 3],
        [−1.75, 1.5],
        [−1.5, 1.75].

*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return (x + 2) * pow(x + 1,2) * x * pow(x - 1,3)*(x - 2);
}

double bisectionMethod(double (*func)(double),double tol,double interval[2],int maxIteractions){
    double a = interval[0];
    double FA = f(a);
    double b = interval[1];
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = a + (b - a)/2;
        double FP = f(p);

        if(FP == 0 || (b - a)/2 < tol){
            return p;
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
    printf("Method failed after %d iteractions",i);
    return -1;
}

int main(){
    double tol = pow(10,-5);
    double interval1[2] = {-3,2.5};
    double interval2[2] = {-2.5,3};
    double interval3[2] = {-1.75,1.5};
    double interval4[2] = {-1.5,1.75};
    int maxIteractions = 50;

    printf("Solution for the equation within [-3,2.5]: %.5f",bisectionMethod(f,tol,interval1,50));
    printf("\nSolution for the equation within [-2.5,3]: %.5f",bisectionMethod(f,tol,interval2,50));
    printf("\nSolution for the equation within [-1.75,1.5]: %.5f",bisectionMethod(f,tol,interval3,50));
    printf("\nSolution for the equation within [-1.5,1.75]: %.5f",bisectionMethod(f,tol,interval4,50));
    return 0;
}