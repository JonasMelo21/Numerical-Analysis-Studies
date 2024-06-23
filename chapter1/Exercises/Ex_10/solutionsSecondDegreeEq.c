/* /*
   Created by Jonas H. Melo on 22/06/2024
   This code is licensed under MIT license


   This code is part of my studies in numerical analysis,
   following Section 3 of Chapter 1 in the book "Numerical Analysis"
   by Richard L. Burden and J. Douglas Faires, 11th edition.


   Book: Numerical Analysis
   Authors: Richard L. Burden, J. Douglas Faires
   Edition: 11th
   Chapter: 1, Section 3

   The following code aims to solve the exercise presented in README file

   Approach.: Implementing two methods for evaluating 1nd degree polynomial solutions
*/
#include <stdio.h>
#include <math.h>

double discriminant(double a, double b, double c) {
    return ((b * b) - (4 * a * c));
}

void standard_solution(double a, double b, double c, double solutions[2]) {
    double disc = discriminant(a, b, c);
    if (disc >= 0) {
        solutions[0] = (-b + sqrt(disc)) / (2 * a);
        solutions[1] = (-b - sqrt(disc)) / (2 * a);
    } else {
        printf("Non real solution for standard solution (negative discriminant)\n");
        solutions[0] = solutions[1] = NAN;
    }
}

void alternative_solution(double a, double b, double c, double solutions[2]) {
    double disc = discriminant(a, b, c);
    if (disc >= 0 && b != 0) {
        solutions[0] = -2 * c / (b + sqrt(disc));
        solutions[1] = -2 * c / (b - sqrt(disc));
    } else {
        printf("Non real solution for alternative solution (negative discriminant or b is zero)\n");
        solutions[0] = solutions[1] = NAN;
    }
}

int main() {
    double a, b, c;
    double solutions[2];

    printf("\nType the coefficients a, b, and c of the 2nd degree equation:\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    standard_solution(a, b, c, solutions);
    printf("Solutions: %f %f\n", solutions[0], solutions[1]);

    alternative_solution(a, b, c, solutions);
    printf("Alternative Solutions: %f %f\n", solutions[0], solutions[1]);

    return 0;
}
