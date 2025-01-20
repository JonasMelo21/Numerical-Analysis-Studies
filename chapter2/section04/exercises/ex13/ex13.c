/*
    Created by Jonas H. Melo on 2025/01/13
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 1 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: 
    The question title tells us to compare the quadratic and cubic convergence for the function
        f(x) = exp(x) − x − 1
    Using the cubic convergence method given in the question title
*/

#include<math.h>
#include<stdio.h>

double f(double x){
    return exp(x) - x - 1;
}

double derivative(double x){
    return exp(x) - 1;
}

double secondDerivative(double x){
    return exp(x);
}

int main(){
    double p0 = 1;
    double p_quad;
    double tolerance = pow(10,-6);
    int maxIteractions = 20;


    // Quadratic Method Results
    printf("\n\tQuadratic Method\nInitial Guess: %.f",p0);
    for(int i = 1; i <= maxIteractions;i++){
        p_quad = p0 - (f(p0) * derivative(p0)) / (derivative(p0) * derivative(p0) - f(p0) * secondDerivative(p0));
        printf("\nIteraction: %d\tPn:%.5f\t |Pn - Pn-1|: %.5f",i,p_quad,p_quad - p0);
        p0 = p_quad;
    }

    // Cubic Method Results
    p0 = 1;
    double p_cubic;
    printf("\n\n\tCubic Method\nInitial Guess: %.5f",p0);
    for(int i = 1;i <= maxIteractions;i++){
        p_cubic = p0 - (f(p0) / derivative(p0)) - ((secondDerivative(p0) / (2 * derivative(p0))) * ( (f(p0) / derivative(p0)) * (f(p0) / derivative(p0))));
        printf("\nIteraction: %d\tPn:%.5f\t |Pn - Pn-1|: %.5f", i, p_cubic, fabs(p_cubic - p0));
        p0 = p_cubic;
    }

    /*Output:
                        Quadratic Method
        Initial Guess: 1
        Iteraction: 1	Pn:-0.23421	 |Pn - Pn-1|: -1.23421
        Iteraction: 2	Pn:-0.00846	 |Pn - Pn-1|: 0.22575
        Iteraction: 3	Pn:-0.00001	 |Pn - Pn-1|: 0.00845
        Iteraction: 4	Pn:-0.00000	 |Pn - Pn-1|: 0.00001
        Iteraction: 5	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 6	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 7	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 8	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 9	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 10	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 11	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 12	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 13	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 14	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 15	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 16	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 17	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 18	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 19	Pn:-0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 20	Pn:-0.00000	 |Pn - Pn-1|: 0.00000

            Cubic Method
        Initial Guess: 1.00000
        Iteraction: 1	Pn:0.44376	 |Pn - Pn-1|: 0.55624
        Iteraction: 2	Pn:0.17930	 |Pn - Pn-1|: 0.26445
        Iteraction: 3	Pn:0.06929	 |Pn - Pn-1|: 0.11002
        Iteraction: 4	Pn:0.02629	 |Pn - Pn-1|: 0.04300
        Iteraction: 5	Pn:0.00990	 |Pn - Pn-1|: 0.01638
        Iteraction: 6	Pn:0.00372	 |Pn - Pn-1|: 0.00618
        Iteraction: 7	Pn:0.00140	 |Pn - Pn-1|: 0.00232
        Iteraction: 8	Pn:0.00052	 |Pn - Pn-1|: 0.00087
        Iteraction: 9	Pn:0.00020	 |Pn - Pn-1|: 0.00033
        Iteraction: 10	Pn:0.00007	 |Pn - Pn-1|: 0.00012
        Iteraction: 11	Pn:0.00003	 |Pn - Pn-1|: 0.00005
        Iteraction: 12	Pn:0.00001	 |Pn - Pn-1|: 0.00002
        Iteraction: 13	Pn:0.00000	 |Pn - Pn-1|: 0.00001
        Iteraction: 14	Pn:0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 15	Pn:0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 16	Pn:0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 17	Pn:0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 18	Pn:0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 19	Pn:0.00000	 |Pn - Pn-1|: 0.00000
        Iteraction: 20	Pn:0.00000	 |Pn - Pn-1|: 0.00000
*/

    return 0;
}