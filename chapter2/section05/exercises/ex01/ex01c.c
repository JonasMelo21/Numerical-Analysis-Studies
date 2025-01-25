/*
    Created by Jonas H. Melo on 2025/01/25
    This file is protected under the MIT license.

    This code is part of my studies in numerical analysis,
    following Section 5 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach:
    This program computes the first 5 terms of an Aitken's sequence 
    based on the recurrence relation:
        p0 = 0.5,
        pn = 3^(-x), n ≥ 1
    where `x` is the previous term.

    Aitken's Δ² acceleration formula is used to accelerate the convergence of the sequence:
        A_n = p_n - ((p_{n+1} - p_n)^2) / (p_{n+2} - 2*p_{n+1} + p_n)

    The sequence and the corresponding Aitken's sequence are printed step-by-step.
*/

#include <math.h>
#include <stdio.h>


// Function to compute the nth term of the sequence based on the recurrence relation
double f(double x) {
    return pow(3,-x);
}

int main() {
    // Initial term of the sequence
    double p0 = 0.5;

    // Print an introduction message
    printf("\nLet's generate the first 5 terms of a sequence using Aitken's method!\n");

    // Arrays to store the sequence and the Aitken's sequence
    double sequence[7];          // Stores terms of the original sequence (n+1 and n+2 terms are needed)
    double aitkens_sequence[5];  // Stores terms of the Aitken's sequence
    sequence[0] = p0;            // Initialize the sequence with the first term

    // Generate the original sequence up to the 7th term (including extra terms for Aitken's formula)
    double previous_term, new_term;
    for (int i = 1; i <= 7; i++) {
        previous_term = sequence[i - 1];  // Get the previous term
        new_term = f(previous_term);     // Compute the next term using the recurrence relation
        sequence[i] = new_term;          // Store the new term in the sequence array
    }

    // Print all terms of the original sequence
    for (int j = 0; j <= 7; j++) {
        printf("Sequence term %d: %.3f\n", j, sequence[j]);
    }
    printf("\n");

    // Generate the Aitken's sequence
    double aitkens_term;  // Variable to store each Aitken's term
    int aitken_index = 0;

    // Calculate the Aitken's terms using the formula
    while (aitken_index < 5) {
        int p = aitken_index;    // Index for the current term
        int p1 = p + 1;          // Index for the next term
        int p2 = p + 2;          // Index for the term after the next

        // Pre-fetch terms to simplify readability in the formula
        double current = sequence[p];
        double next = sequence[p1];
        double next_next = sequence[p2];

        // Apply Aitken's Δ² acceleration formula
        aitkens_term = current - ((next - current) * (next - current) / (next_next - 2 * next + current));

        // Store the computed Aitken's term in the array
        aitkens_sequence[aitken_index] = aitkens_term;
        aitken_index++;
    }

    // Print all terms of the Aitken's sequence
    for (int k = 0; k < 5; k++) {  // Loop through the first 5 terms of the Aitken's sequence
        printf("Aitken's term %d: %.5f\n", k, aitkens_sequence[k]);
    }

    return 0;
}
