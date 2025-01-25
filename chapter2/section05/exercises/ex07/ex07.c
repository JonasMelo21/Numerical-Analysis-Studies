/*
    This code was created by Jonas H Melo on 2025/25/01
    This file is protected under MIT license

    This code is part of my studies on the field of Numerical Analysis
    Following the Section 05 from Chapter 02 from the text book 
    "Numerical Analysis" by Richard L Burden and Douglas J Faires
    
    Approach:
    The question wants us to use Stefesen's Method and  find a solution with 10^(-4) of accuraccy
    for the equation x^3 - x - 1 = 0, within [1,2] and compare to the results of
    Exercise 6 of Section 02 of this chapter which asked us to 
*/

#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x,3) - 1;
}

double stefensenMethod(double p0, double tolerance, int maxIteractions){
    int i = 1;
    while(i <= maxIteractions){
        double p1 = f(p0);
        double p2 = f(p1);
        double p = p0 - pow((p1 - p0),2) / (p2 - 2*p1 +p0);
        if(fabs(p - p0) < tolerance){
            printf("\nStefensen Method Success(%d iteractions)\n",i);
            return p;
        }
        p0 = p;
        i++;
    }
    return -1;
}

int main(){
    double tolerance = pow(10,-4);
    double p0 = 2;
    int max = 50;
    double solution = stefensenMethod(p0,tolerance,max);
    if(solution == -1){
        printf("\nStefensen Method Failed\n");
    }else{
        printf("\nSolution(Root): %.5f",solution);
    }
    return 0;
}