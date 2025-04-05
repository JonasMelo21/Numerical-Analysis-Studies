/*
    Created by Jonas H. Melo on 2025/03/24
    This file is protected under the MIT license.

    This code is part of my studies in numerical analysis,
    following Section 6 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach:
    This programm aims to compute the root of the equation below by Muller Method
    f(x) = x^3 + 3x^2 - 1 
    With 4 digits of tolerance
*/

#include <math.h>
#include <stdio.h>

double f(double x){
    return pow(x,3) + 3 * pow(x,2) - 1;
}


double mullerMethod(double p0,double p1, double p2,double tolerance, int maxIteractions){
    double p;
    double h;
    double h1 = p1 - p0;
    double h2 = p2 - p1;
    double q1 = (f(p1) - f(p0)) / h1;
    double q2 = (f(p2) - f(p1)) / h2;
    double d = (q2 - q1) / (h2 + h1);
    double b;
    double g;
    int i = 3;
    double e;

    while(i < maxIteractions){
        b = q2 + h2*d;

        double discriminant = b*b - 4*f(p2)*d;
        if (discriminant < 0){
            printf("\nDiscriminant is negative at iteration %d. Aborting.\n", i);
            return -1;
        }

        g = sqrt(discriminant);
        e = (fabs(b - g) < fabs(b + g)) ? b + g : b - g;

        if (e == 0){
            printf("\nDivision by zero at iteration %d. Aborting.\n", i);
            return -1;
        }

        h = -2*f(p2) / e;
        p = p2 + h;
        if(fabs(h) < tolerance){
            printf("\nMuller Method Executed Successfully after %d iterations\n", i);
            return p;
        }

        p0 = p1;
        p1 = p2;
        p2 = p;

        h1 = p1 - p0;
        h2 = p2 - p1;
        q1 = (f(p1) - f(p0)) / h1;
        q2 = (f(p2) - f(p1)) / h2;
        d = (q2 - q1) / (h2 + h1);
        i++;
    }

    printf("\nMuller Method did not converge within %d iterations\n", maxIteractions);
    return -1;
}

int main(){
    double tolerance = pow(10,-4); // alternative: 0.0001
    double p0 = 0;
    double p1 = 0.5;
    double p2 = 1.0;
    int maxIteractions = 50;
    double solution = mullerMethod(p0,p1,p2,tolerance,maxIteractions);
    if(solution == -1){}
    else{
        printf("Root of the equation between 0 and 1 (for p0 = %.5f,p1 = %.5f and p2 = %.5f) ---> %.5f\n",p0,p1,p2,solution);
    }

    p0 = -1;
    p1 = -1.5;
    p2 = -2;
    solution = mullerMethod(p0,p1,p2,tolerance,maxIteractions);
    if(solution == -1){
        printf("\nMuller method failed for p0 = %.5f, p1 = %.5f,p2 = %.5f\n",p0,p1,p2);
    }
    else{
        printf("Root of the equation between 0 and -1 (for p0 = %.5f,p1 = %.5f and p2 = %.5f) ---> %.5f\n",p0,p1,p2,solution);
    }


    p0 = -1;
    p1 = -2;
    p2 = -3;
    solution = mullerMethod(p0,p1,p2,tolerance,maxIteractions);
    if(solution == -1){
        printf("\nMuller method failed for p0 = %.5f, p1 = %.5f,p2 = %.5f\n",p0,p1,p2);
    }
    else{
        printf("Root of the equation between -3 and -2 (for p0 = %.5f,p1 = %.5f and p2 = %.5f) ---> %.5f\n",p0,p1,p2,solution);
    }

    /*
    Output:
        Muller Method Executed Successfully after 5 iterations
        Root of the equation between 0 and 1 (for p0 = 0.00000,p1 = 0.50000 and p2 = 1.00000) ---> 0.53209

        Muller Method Executed Successfully after 7 iterations
        Root of the equation between 0 and -1 (for p0 = -1.00000,p1 = -1.50000 and p2 = -2.00000) ---> -0.65270

        Muller Method Executed Successfully after 6 iterations
        Root of the equation between -3 and -2 (for p0 = -1.00000,p1 = -2.00000 and p2 = -3.00000) ---> -2.87939
    */

    return 0;
}