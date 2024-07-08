/*
    Created by Jonas H. Melo on 07/04/2024
    This code is lincensed under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach.: We will compute the solution for the equation
    x^3 - 7x^2 + 14x - 6 = 0 with accuracy of 0.001
    on the intervals [0,1] , [1,3.2] , [3.2,4]
    by Bisection Method

*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x,3) - 7*(pow(x,2)) + 14*x - 6;
}

double bisectionMethod(double[2] interval,double tol,int maxIteractions,double(*func)(double)){

    double a = interval[0];
    double b = interval[1];

    if(a * b > 0){
        printf("a and b must be opposite signs\n");
        return -1;
    }

    int i = 1;
    double FA = func(a);

    while(i <= maxIteractions){
        double p = a + (b - a)/2;
        double FP = func(p);
        if(FP == 0 || (b - a) / 2 < tol){
            return p;
        }    
    
        i++;
        if(FP * FA > 0){
            a = p;
            FA = FP;
        }else{
            b = p;
        }
    }
    printf("Method failed after %d Iteractions",i);
}

int main(){
    double x1 = bisectionMethod([0,1],0.01,50,f);
    printf("\nSolution on the interval: [0,1]: %.2f",x1);

    double x2 = bisectionMethod([1,3.2],0.01,50,f);
    printf("\nSolution on the interval: [0,1]: %.2f",x2);
    
    double x3 = bisectionMethod([3.2,4],0.01,50,f);
    printf("\nSolution on the interval: [0,1]: %.2f",x3);

    
}