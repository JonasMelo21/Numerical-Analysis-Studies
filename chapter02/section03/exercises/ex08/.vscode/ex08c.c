/*
    Created by Jonas H. Melo on 2024/10/06
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Secant's method to find root 
    of  the equation f(x) = 2x*cos(2x) − (x − 2)^2 = 0 
    within [2,3] and [3,4] with 4 digits of accuracy.
*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return 2*x*cos(2*x) - pow(x-2,2);
}

int main(){
    double tolerance = pow(10,-4);
    double p0 = 2;
    double p1 = 3;
    double p;
    int i = 2;
    int maxIteractions = 50;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tolerance){
            printf("\nMethod executed successfully after %d iteractions",i);
            printf("\nRoot for 2 and 3: %.5f",p);
            break;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    if(i > maxIteractions){
        printf("\nMethod failed");
    }

    p0 = 3;
    p1 = 4;
    
    int j = 2;
    
    while(j <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tolerance){
            printf("\nMethod executed successfully after %d iteractions",i);
            printf("\nRoot for 4 and 3: %.5f",p);
            break;
        }
        p0 = p1;
        p1 = p;
        j++;
    }
    if(j > maxIteractions){
        printf("\nMethod failed");
    }
    return 0;

}