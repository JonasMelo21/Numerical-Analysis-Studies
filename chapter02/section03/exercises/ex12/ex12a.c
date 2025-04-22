/*
    Created by Jonas H. Melo on 2024/11/8
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use all methods in this section to find the solution for 
    x^2 − 4x + 4 − ln x = 0 for 1 ≤ x ≤ 2 and for 2 ≤ x ≤ 4
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x,2) - 4*x + 4 -log(x);
}

double derivative_f(double x){
    return 2*x -4 -(1 / x);
}

double newtonMethod(double p0,double tol, int maxIteractions){
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = p0 - (f(p0)) / (derivative_f(p0));
        if(fabs(p - p0) < tol){
            printf("Newton Method executed successfully after %d iteractions\n",i);
            return p;
        }
        p0 = p;
        i++;
    }
    return -1;
}

double secantMethod(double p0,double p1,double tolerance,int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tolerance){
            printf("Secant method executed succesfully after %d iteractions\n",i);
            return p;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    return -1;
}

double falsePosition(double p0,double p1,double tol, int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tol){
            printf("False Position Method executed successfully after %d iteractions\n",i);
            return p;
        }
        if(f(p) * f(p1) < 0){
            p0 = p1;
        }
        p1 = p;
        i++;
    }
    return -1;
}

int main(){
    double n0 = 2;
    double tolerance = pow(10,-7);
    int max = 30;

    double newton1 = newtonMethod(n0,tolerance,max);
    if(newton1 == -1){
        printf("Newton Method failed for [1,2]\n");
    }
    else if(newton1 != -1){
        printf("Newton Method Solution within [1,2]: %.7f\n\n",newton1);
    }

    double p0 = 1;
    double p1 = 2;
    double secant1 = secantMethod(p0,p1,tolerance,max);
    if(secant1 == -1){
        printf("Secant Method failed for [1,2]\n");
    }
    else if(secant1 != -1){
        printf("Secant Method Solution within [1,2]: %.7f\n\n",secant1);
    }

    double falsePosition(p0,p1,tolerance,max);
    if(falsePosition == -1){
        printf("False Position Method failed for [1,2]\n");
    }
    else if(falsePosition != -1){
        printf("False Position Method Solution within [1,2]: %.7f\n\n",falsePosition);
    }
    

    n0 = 4;
    double solution2 = newtonMethod(n0,tolerance,max);
    if(solution2 == -1){
        printf("Newton Method failed for [2,4]");
    }
    else if(solution2 != -1){
        printf("Solution with Newton Method for [2,4]: %.7f\n",solution2);
    }

    p0 = 2;
    p1 = 4;
    double secant2 = secantMethod(p0,p1,tolerance,max);
    if(secant2 == -1){
        printf("Secant Method failed for [2,4]\n");
    }
    else if(secant2 != -1){
        printf("Solution with Secant Method for [2,4]: %.7f\n",secant2);
    }
    
    double falsePosition2 = falsePosition(p0,p1,tolerance,max);  
    if(falsePosition2 == -1){
        printf("False Position Method failed for [2,4]\n");
    }
    else if(falsePosition2 != -1){
        printf("Solution with False Position Method for [2,4]: %.7f\n",falsePosition2);
    }
    
    
    return 0;
}