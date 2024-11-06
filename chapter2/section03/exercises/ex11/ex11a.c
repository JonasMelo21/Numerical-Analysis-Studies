/*
    Created by Jonas H. Melo on 2024/11/6
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use all methods in this section to find the solution for 3x*e^x = 0 for 1 ≤ x ≤ 2
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return 3*x*exp(x);
}

double derivative_f(double x){
    return 3*exp(x) + 3*x*exp(x);
}

double newtonMethod(double p0, double tol,int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p0 - f(p0) / derivative_f(p0);
        if(fabs(p - p0) < tol){
            printf("\n\nNewton method executed successfully after %d iteractions\n",i);
            return p;
        }
        p0 = p;
        i++;
    }
    if(maxIteractions < i){
        return -1;
    }
}

double secantMethod(double p0,double p1,double tol, int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tol){
            printf("Secant method executed successfully after %d iteractions\n",i);
            return p;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    if(i > maxIteractions){
        return -1;
    }
}
double falsePosition(double p0,double p1,double tol,int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p0)){
            printf("False position method executed successfully after %d iteractions\n",i);
            return p;
        }
        if(f(p) * f(p1) < 0){
            p0 = p1;
        }
        p1 = p;
        i++;
    }
    if(maxIteractions < i){
        return -1;
    }
}

int main(){
    double p0 = 1;
    double p1 = 2;
    double tol = pow(10,-5);
    int maxIteractions = 30;

    double solution1 = newtonMethod(p0,tol,maxIteractions);
    double solution2 = secantMethod(p0,p1,tol,maxIteractions);
    double solution3 = falsePosition(p0,p1,tol,maxIteractions);
    if(solution1 != -1){
        printf("Solution for 3*x*exp(x) = 0 by Newton Method is: %.5f\n",solution1);
    }
    if(solution1 == -1){
        printf("Newton Method failed\n");
    }
    if(solution2 != -1){
        printf("Solution for 3*x*exp(x) by Secant Method is: %.5f\n",solution2);
    }
    if(solution2 == -1){
        printf("Secant method failed\n");
    }
    if(solution3 != -1){
        printf("False position method for 3*x*exp(x) is: %.5f\n",solution3);
    }
    if(solution3 == -1){
        printf("False position method failed\n");
    }

    // Output:
    // Newton method executed successfully after 7 iteractions
    // Secant method executed successfully after 10 iteractions
    // False position method executed successfully after 2 iteractions
    // Solution for 3*x*exp(x) = 0 is: 0.00000
    // Solution for 3*x*exp(x) is: 0.00000
    // False position method for 3*x*exp(x) is: 0.77460
    return 0;
}