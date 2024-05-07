/*
   Created by Jonas H. Melo on 05/06/2024
   This code is licensed under MIT license


   This code is part of my studies in numerical analysis,
   following Section 3 of Chapter 1 in the book "Numerical Analysis"
   by Richard L. Burden and J. Douglas Faires, 11th edition.


   Book: Numerical Analysis
   Authors: Richard L. Burden, J. Douglas Faires
   Edition: 11th
   Chapter: 1, Section 3

   This code calculates the sum of the first 'n' natural numbers using a function 'sum'.
   The 'sum' function takes an integer 'n' as input,
   and it returns the sum of the first 'n' natural numbers.
   It achieves this by iterating through each natural number from 0 to 'n'
   and accumulating the sum.
*/

#include <stdio.h>

// Function to calculate the sum of the first 'n' natural numbers
int sum(int n) {
    int result = 0;                     // Initialize the variable 'result' to store the sum
    for(int i = 1; i <= n; i++) {       // Iterate from 1 to 'n' (not from 0 to 'n')
        result = result + i;            // Add each number to the variable 'result'
    }
    return result; // Return the sum
}

// Main function where the program execution starts
int main() {
    // Print the result of the 'sum' function with argument 4
    printf("\nThe value of the sum of the first 4 natural numbers is: %d\n", sum(4)); // Output: 10

    // Receiving Nth number as an input
    printf("Type how many numbers do you wanna add: ");
    int num;
    scanf("%d", &num);                                                        // Read the number of digits from the user
    printf("Sum of digits from 0 to %d is: %d\n", num, sum(num));          // Print the sum of the first 'num' natural numbers
    return 0;                                                                       // Return 0 to indicate successful execution
}
