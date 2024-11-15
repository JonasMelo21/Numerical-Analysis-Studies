/*
    Created by Jonas H. Melo on 2024/11/9
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: We're gonna use all methods in this section to find the solution for 
    x + 1 − 2 sin(πx) = 0 for 0 ≤ x ≤ 1/2 and for 1/2 ≤ x ≤ 1
*/

#include<stdio.h>
#include<math.h>


double f(double x){
    return x + 1 - 2*sin(M_PI*x);
}

double derivative_f(double x){
    return 1 -2*cos(M_PI*x)*M_PI;
}

double newtonMethod(double p0,double tolerance,int maxIteractions){
    double p;
    int i =1;
    while(i <= maxIteractions){
        p = p0 - (f(p0)) / (derivative_f(p0));
        if(fabs(p - p0) < tolerance){
            printf("\nNewton method executed successfully after %d iteractions\n",i);
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
            printf("\nSecant Method executed successfully after % d iteractions\n",i);
            return p;
        }
        p0 = p1;
        p1 = p;
        i++;
    }
    return -1;
}

double falsePosition(double p0,double p1, double tol,int maxIteractions){
    double p;
    int i =2;
    while(i <= maxIteractions){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        if(fabs(p - p1) < tol){
            printf("\nFalse Position Method executed correctly after %d iteractions\n",i);
            return  p;
        }
        if(f(p) * f(p1) < 0){
            p0 = p1;
        }
        p1 = p;
        i++;
    }
    return -1;
}


/// @brief 
/// @return 
int main(){
    
    double tol = pow(10,-7);
    int max = 30;
    

    double n0 = 1/2;
    double newton1 = newtonMethod(n0,tol,max);
    if(newton1 != -1){
        printf("Newton Method's solution for [0,1/2]: %.7f\n",newton1);
    }
    else if(newton1 == -1){
        printf("Newton Method failed\n");
    }

    double n1 = 1;
    double newton2 = newtonMethod(n1,tol,max);
    if(newton2 == -1){
        printf("Newton Method failed for [1/2,1]\n");
    }
    else if(newton2 != -1){
        printf("Newton Method Solution for [1/2,1]: %.7f\n\n",newton2);
    }


    double s0 = 0;
    double s1 = 0.5;
    double secant1 = secantMethod(s0,s1,tol,max);
    if(secant1 == -1){
        printf("Secant Method Failed\n");
    }
    else if(secant1 != -1){
        printf("Secant Method Solution for [0,0.5]: %.7f\n",secant1);
    }

    double s2 = 0.5;
    double s3 = 1;
    double secant2 = secantMethod(s2,s3,tol,max);
    if(secant2 == -1){
        printf("Secant Method Failed\n");
    }
    else if(secant2 != -1){
        printf("Secant Method Solution for [0.5,1]: %.7f\n",secant2);
    }

    double false1 = falsePosition(s0,s1,tol,max);
    if(false1 == -1){
        printf("False Position Method failed for [0,0.5]\n");
    }
    else if(false1 != -1){
        printf("False Position Solution for [0,0.5]: %.7f\n",false1);
    }

    double false2 = falsePosition(s2,s3,tol,max);
    if(false2 == -1){
        printf("False Position for [0.5,1]: %.7f\n",false2);
    }
    else if(false2 != -1){
        printf("False Position Solution for [0.5,1]:%.7f",false2);
    }

    /*
    Output:
    Newton method executed successfully after 5 iteractions
    Newton Method's solution for [0,1/2]: 0.2060351

    Newton method executed successfully after 5 iteractions
    Newton Method Solution for [1/2,1]: 0.6819748


    Secant Method executed successfully after  9 iteractions
    Secant Method Solution for [0,0.5]: 0.2060351

    Secant Method executed successfully after  8 iteractions
    Secant Method Solution for [0.5,1]: 0.6819748

    False Position Method executed correctly after 12 iteractions
    False Position Solution for [0,0.5]: 0.2060351

    False Position Method executed correctly after 15 iteractions
    False Position Solution for [0.5,1]:0.6819748
    */

    return 0;
}