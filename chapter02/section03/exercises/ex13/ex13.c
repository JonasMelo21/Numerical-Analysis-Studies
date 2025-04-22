/*
    Created by Jonas H. Melo on 2024/11/15
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use all methods in this section to find the solution for 
    4x^3 + 2x - 2 = 0 where x,x^2 is closes to (1,0).
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return 4*pow(x,3) +2*x - 2;
}

double derivative(double x){
    return 12*pow(x,2) + 2;
}

int main(){
    double tol = pow(10,-4);
    int max = 30;
    double p0 = 1;
    double p;
    int i = 1;
    while(i <= max){
        p = p0 - f(p0) / derivative(p0);
        if(fabs(p - p0) < tol){
            printf("\nNewton Method executed successfully after %d iteractions\n",i);
            printf("Solution: %.4f\n",p);
            break;
        }
        p0 = p;
        i++;
    }
    if(i > max){
        printf("Method failed");
    }

    // Output:
    // Newton Method executed successfully after 5 iteractions
    // Solution: 0.5898

    return 0;
}