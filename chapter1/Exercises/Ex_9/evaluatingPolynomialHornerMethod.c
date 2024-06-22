/* /*
   Created by Jonas H. Melo on 05/06/2024
   This code is licensed under MIT license


   This code is part of my studies in numerical analysis,
   following Section 3 of Chapter 1 in the book "Numerical Analysis"
   by Richard L. Burden and J. Douglas Faires, 11th edition.


   Book: Numerical Analysis
   Authors: Richard L. Burden, J. Douglas Faires
   Edition: 11th
   Chapter: 1, Section 3
   
   The following code aims to answer the question showed in the README, which is:
   Create an algorithm to evaluate any polynomial P(x0) such that
   P(x0) = An*(X^n) + An-1*(X^n-1)+...A1*(X^1) 
   Using Nested Multiplication
   
   Approach: We will use Horner's method for evaluating the polynomial P(x) = x^3 - 6,1(x^2) + 3,2x + 1.5
   For x = 4.71
   */

# include<stdio.h>

double polynomialSolution(double coeficients[], int size, double x,double constant_term){
    double result = 0;
    for(int i = 0; i < size; i++){
        result += coeficients[i];
        result *= x;
    }
    result += constant_term;
    return result;
}

int main(){
    double coeficients[3] = {1,-6.1,+3.2};
    int size = sizeof(coeficients) / sizeof(coeficients[0]);
    double constant_term = 1.5;
    double x = 4.71;
    printf("Polynomial:\nP(x) = x^3 -6.1(x^2) + 3.2x + 1.5\nValue of x = 4.71\n");

    printf("\nP(X) Evaluated with Nested Multiplication for X = 4.71 with 3 digits: %.3f\n",polynomialSolution(coeficients,size,x,constant_term));

    printf("\nP(X) Evaluated with Nested Multiplication for X = 4.71 with 5 digits: %.5f\n",polynomialSolution(coeficients,size,x,constant_term));

    printf("\nP(X) Evaluated with Nested Multiplication for X = 4.71 with 7 digits: %.7f\n",polynomialSolution(coeficients,size,x,constant_term));
    return 0;
}