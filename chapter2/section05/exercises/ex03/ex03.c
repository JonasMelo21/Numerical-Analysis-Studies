/*
    Created by Jonas H. Melo on 2025/01/25
    This file is protected under the MIT license.

    This code is part of my studies in numerical analysis,
    following Section 5 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach:
    Let's use Steffesen's Algorithm to find the 1_st term of the sequence 
        g(x) = cos(x - 1)
    {Pn} with p0 = 2 
    Where P0 will be generated by Aitkens Method

    Aitken's Δ² acceleration formula is used to accelerate the convergence of the sequence:
        A_n = p_n - ((p_{n+1} - p_n)^2) / (p_{n+2} - 2*p_{n+1} + p_n)

    The sequence and the corresponding Aitken's sequence are printed step-by-step.
*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return cos(x-1);
}

int main(){
    double p0 = 2;
    double p1 = f(p0);
    double p2 = f(p1);
    
    double p = p0 - pow((p1 - p0),2) / (p2 - 2*p1 + p0);

    printf("\nP_{0} with Aitken's Method: %.5f",p);
    return 0;
}