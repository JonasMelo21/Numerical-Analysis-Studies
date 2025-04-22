/*
Created by Jonas H. Melo on 24/06/2024
This code is licensed under MIT license

This code is part of my studies in numerical analysis,
following Section 3 of Chapter 1 in the book "Numerical Analysis"
by Richard L. Burden and J. Douglas Faires, 11th edition.
*/

#include <stdio.h>
#include <math.h>

void numIterations(double x) {
    if (x > 1 || x < -1) {
        printf("The value of x should be between -1 and 1\n");
        return;
    }

    double currentResult = 0;
    double wantedResult = (1 + 2 * x) / (1 + x + pow(x, 2));
    int i = 1;

    while (i <= 20000) {  // Limite de iterações para evitar loop infinito
        double numerator = (pow(2, i - 1) * pow(x, pow(2, i - 1) - 1) - pow(2, i) * pow(x, pow(2, i - 1)));
        double denominator = 1 - pow(x, pow(2, i - 1)) + pow(x, pow(2, i));

        currentResult += numerator / denominator;

        if (fabs(wantedResult - currentResult) < 0.000001) {
            printf("Current Result: %.6f\n", currentResult);
            printf("Actual Result: %.6f\n", wantedResult);
            printf("Number of iterations done: %d\n", i);
            return;
        }
        i++;
    }

    printf("Max iterations reached without achieving the desired accuracy.\n");
    printf("Current Result: %.6f\n", currentResult);
    printf("Actual Result: %.6f\n", wantedResult);
    printf("Number of iterations done: %d\n", i - 1);
}

int main() {
    double x = 0.25;
    numIterations(x);
    return 0;
}
