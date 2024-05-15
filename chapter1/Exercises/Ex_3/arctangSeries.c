/*
 * Created by Jonas H. Melo on 05/06/2024
   This code is licensed under MIT license

   This code is part of my studies in numerical analysis,
   following Section 3 of Chapter 1 in the book "Numerical Analysis"
   by Richard L. Burden and J. Douglas Faires, 11th edition.


   Book: Numerical Analysis
   Authors: Richard L. Burden, J. Douglas Faires
   Edition: 11th
   Chapter: 1, Section 3

   The following code aims to compute the value
   for arctan(x) by calculating the Taylor Series:
   arctan(x) = ((-1)^(i + 1)) * ((x^(2*i + 1)) / (2 * i + 1))
   for 1 <= i <= n,
   where n is given by the user.
 */

#include <stdio.h>
#include <math.h>

// Function to compute the arctangent using Taylor series expansion
double arctanSeries(double x, double tolerance, int maxIterations) {
    double sum = 0; // Initialize the sum
    double term = x; // Initialize the first term
    int sign = 1; // Start with a positive sign as the first term is positive.

    for (int i = 1; i <= maxIterations; i++) {
        sum += sign * term; // Add the term to the sum
        term *= (x * x) / (2 * i + 1); // Update the term for the next term in the series.
        sign = -sign; // Alternate the sign for the next term.

        // Check if the term is within the specified tolerance
        if (fabs(term) < tolerance)
            return sum; // Return the sum if within tolerance
    }

    return sum; // Return the sum if the maximum iterations are reached without meeting tolerance
}

// Function to convert radians to degrees
double convertRadToDeg(double angRad) {
    if (angRad < 0) {
        return -1; // Return -1 if the input angle is negative (considering error handling).
    }

    return angRad * 180 / M_PI; // Convert radians to degrees
}

int main() {
    printf("\nAngle in degrees for which tangent is 1\n");
    printf("%f\n", convertRadToDeg(arctanSeries(1, 0.001, 50))); // Print the result in degrees
    return 0;
}
