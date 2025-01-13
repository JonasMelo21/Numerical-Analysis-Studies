/*
    Created by Jonas H. Melo on 2025/01/12
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: 
    The question title tells us to use Newton Method to find the solution for
        cos(x + √2) + x(x/2 + √2) = 0, 
    For -2 ≤ x ≤ -1 with 5 digits of accuracy. 
    But we're gnna go further and compare the performance of all root finding methods studied so far, which are:
    -   Traditional Newton Method
    -   Bisection Method
    -   Secant Method
    -   False Position Method
    -   Modified Newton Method

*/
#include<math.h>
#include<stdio.h>


// Function we want to find the root
double f(double x){
    return cos(x + sqrt(2)) + x*(x/2 + sqrt(2));
}

// Derivative that will be used in Traditional Newton Method
double derivative(double x){
    return x + sqrt(2) - sin(x + sqrt(2));
}

// Second Derivative for Modified Newton Method
double secondDerivative(double x){
    return 1 - cos(x + sqrt(2));
}

// Traditional Newton Method
double newtonMethod(double p0, int maxIteractions,double tolerance){
    double a0 = p0;
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = a0 - (f(a0) / derivative(a0));
        if(fabs(p - a0) < tolerance || f(p) == 0){
            printf("\nTraditional Newton Method Executed Successfully after %d iteractions for cos(x + √2) + x(x/2 + √2) = 0 with p0 = %.f\n",i,p0);
            return p;
        }
        a0 = p;
        i++;
    }
    return -1;
}


// Secant Method
double secantMethod(double p0,double p1,int maxIteractions,double tolerance){
    double a0 = p0;
    double a1 = p1;
    double p;
    int i = 2;
    while(i <=maxIteractions){
        p = a1 - (f(a1) * (a1 - a0)) / (f(a1) - f(a0));
        if(fabs(p - a1) < tolerance || f(p) == 0){
            printf("\nSecant Method Executed Sucessfully after %d iteractions for cos(x + √2) + x(x/2 + √2) = 0 within [-2,-1]\n",i);
            return p;
        }
        a0 = a1;
        a1 = p;
        i++;
    }

    return -1;
}

double falsePositionMethod(double p0,double p1,double tolerance, int maxIteractions){
    double p;
    int i = 2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tolerance || f(p) == 0){
            printf("\nFalse Position Method Executed Successfully after %d iteractions for cos(x + √2) + x(x/2 + √2) = 0 within [-2,-1]\n",i);
            return p;
        }

        if(f(p) * f(p1) < 0){
            p0 = p1;
        }

        p1 = p;
    }
    return -1;
}


double modifiedNewtonMethod(double p0, int maxIteractions,double tolerance){
    double a0 = p0;
    double p;
    int i = 1;
    double numerator, denominator;
    while(i <= maxIteractions){
        numerator = f(a0) * derivative(a0);
        denominator = pow(derivative(a0),2) - f(a0) * secondDerivative(a0);
        p = a0 - numerator / denominator;
        if(fabs(p - a0) < tolerance || f(p) == 0){
            printf("\nModified Newton Method Executed Successfully after %d iteractions\n",i);
            return p;
        }

        a0 = p;
        i++;
    }
    return -1;
}



int main(){
    double tolerance = pow(10,-5);
    int maxIteractions = 50;


    // Testin Traditional Newton Method
    double p0 = -2;
    double newtonSolution = newtonMethod(p0,maxIteractions,tolerance);
    if(newtonSolution == -1){
        printf("\nTraditional Method Failed for cos(x + √2) + x(x/2 + √2) = 0, for p0=%.f ",p0);
    }else{
        printf("Solution: %.5f\n",newtonSolution);
    }

    // Testing Secant Method
    p0 = -2;
    double p1 = -1;
    double secantSolution = secantMethod(p0,p1,maxIteractions,tolerance);
    if(secantSolution == -1){
        printf("\nSecant Method failed for for cos(x + √2) + x(x/2 + √2) = 0 within [-2,-1]\n");
    }else{
        printf("Solution: %.5f\n",secantSolution);
    }


    // Testing False Position Method
    p0 = -2;
    p1 = -1;
    double falsePositionSolution = falsePositionMethod(p0,p1,tolerance,maxIteractions);
    if(falsePositionSolution == -1){
        printf("\nFalse Position Method Failed for cos(x + √2) + x(x/2 + √2) = 0 within [-2,-1]");
    }
    else{
        printf("Solution: %.5f\n",falsePositionSolution);
    }
    

    // Testin Traditional Newton Method
    p0 = -2;
    double modifiedNewtonSolution = modifiedNewtonMethod(p0,maxIteractions,tolerance);
    if(modifiedNewtonSolution == -1){
        printf("\nTraditional Method Failed for cos(x + √2) + x(x/2 + √2) = 0, for p0=%.f ",p0);
    }else{
        printf("Solution: %.5f\n",modifiedNewtonSolution);
    }

    return 0;
}