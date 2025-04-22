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

// Function to calculate the discriminant of a quadratic equation
double discriminant(double a, double b, double c) {
return ((b * b) - (4 * a * c)); // Return the value of the discriminant
}

// Function to find the roots using the standard quadratic formula
void standard_solution(double a, double b, double c, double solutions[2]) {
double disc = discriminant(a, b, c); // Calculate the discriminant
if (disc >= 0) { // Check if the discriminant is non-negative
solutions[0] = (-b + sqrt(disc)) / (2 * a); // Calculate the first root
solutions[1] = (-b - sqrt(disc)) / (2 * a); // Calculate the second root
} else {
// Print a message if the discriminant is negative (no real solutions)
printf("Non real solution for standard solution (negative discriminant)\n");
solutions[0] = solutions[1] = NAN; // Assign NaN to indicate no real solutions
}
}

// Function to find the roots using an alternative quadratic formula
void alternative_solution(double a, double b, double c, double solutions[2]) {
double disc = discriminant(a, b, c); // Calculate the discriminant
if (disc >= 0 && b != 0) { // Check if the discriminant is non-negative and b is non-zero
solutions[0] = -2 * c / (b + sqrt(disc)); // Calculate the first root using the alternative formula
solutions[1] = -2 * c / (b - sqrt(disc)); // Calculate the second root using the alternative formula
} else {
// Print a message if the discriminant is negative or b is zero (no valid solutions)
printf("Non real solution for alternative solution (negative discriminant or b is zero)\n");
solutions[0] = solutions[1] = NAN; // Assign NaN to indicate no valid solutions
}
}

int main() {
double a, b, c; // Coefficients of the quadratic equation
double solutions[2]; // Array to store the solutions
