/*
    Created by Jonas H. Melo on 05/09/2024
    This code is lincensed under MIT license

    This code is part of my studies in numerical analysis,
    following exercise 1 from Section 3 of Chapter 1 in the book
    "Numerical Analysis" by Richard L. Burden
    and J. Douglas Faires, 11th edition.

    Exercise:
    Use three-digit chopping arithmetic to compute the sum
    1/1 + 1/4 + 1/9 + 1/16...1/100 = i/(i^2) for 1 <= 1 <= 10
    and then by 1/100 + 1/81 + 1/64...+1/4 + 1/1. Which is more accurate ?

    Resolution Approach:
    The actual value of Quadratic Harmonic Series(abbreviated as QHS)
    for i from to 10 is 1.549
    So we will develop two distinct algorithms to compute the QHS.
    One in forward order and the other in reverse order.
    Thus, we'll be able to check which one has better accuracy

 */
#include <stdio.h>
#include <math.h>

double quadraticHSeries(int n){
    double sum = 0;
    for(int i = 1; i <= n;i++){
        sum = sum + 1 / pow(i,2);
    }
    return sum;
}

double reverseQHSeries(int n){
    double sum = 0;
    for(int i = n; i > 1; i--){
        sum = sum + i / pow(i,2);
    }
    return sum;
}

int main(){
    double result = quadraticHSeries(10);
    double backwardsResult = reverseQHSeries((10));

    printf("\n3-digit-chopping of 10 first terms of QHS:%.3lf",result);
    // Output --> 1.550

    printf("\nSame computation, but in backwards:%.3lf",backwardsResult);
    // Output --> 1.929

    printf("\nAs the actual value is 1.549, the forward order is more precise");

    return 0;
}
