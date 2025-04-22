/*
    Created by Jonas H. Melo on 07/04/2024
    This code is lincensed under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    The following programm computes P3 from the bisection method applied to the function F(x) = 3(x + 1)(x - 1/2)(x - 1) within the interval [-2, 1.5]    
*/

#include<stdio.h>

// The fucntion we want to find the root
double f(double x){
    return 3*(x + 1)*(x - 1/2)*(x - 1);
}

double main(){
    // Initializing the endpoints of the interval [-2,1.5]
    double a = -2;
    double b = 1.5;
    double FA = f(a);
    double FB = f(b);

    // Loop to find P3
    int i = 1;
    while(i <= 3){
        // Assigning the midpoint of a and b to p
        double p = a + ((b - a)/2);
        double FP = f(p);

        printf("\nIteraction %d\n",i);
        printf("\ta: %.5f ---> FA: %.5f\n",a,FA);
        printf("\tb: %.5f ---> FB: %.5f\n",b,FB);
        printf("\tp: %.5f ---> FP: %.5f\n",p,FP);

        // If F(p) has the same sign of F(a), then the new value of a is p
        if(FP*FA > 0){
            a = p;
            FA = FP;
        }else{
            b = p;
        }
        i++;
    }
    return 0;
}