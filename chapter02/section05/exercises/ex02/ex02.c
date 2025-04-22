#include <math.h>
#include <stdio.h>

// Function to implement the sequence
double f(double x) {
    return exp(6*x) + 3 * pow(log(2),2) * exp(2*x) - log(8)*exp(4*x) - pow(log(2),3);
}

// Derivative of the function
double derivative(double x) {
    return 6*exp(6*x) + 6*pow(log(2),2)*exp(2*x) - 4*log(8)*exp(4*x);
}

int main() {
    // Initial term of the sequence and tolerance
    double p0 = 0;  // Initial guess
    double tolerance = 0.0002;

    // Newton's Method
    printf("Newton's Method:\n");
    double p = p0 - (f(p0) / derivative(p0));
    int i = 1;

    while (fabs(p - p0) >= tolerance) {
        printf("Iteration %d: p = %.9f\n", i, p);
        p0 = p;
        p = p0 - (f(p0) / derivative(p0));
        i++;
    }
    printf("Newton Method Success after %d iterations\n", i);
    printf("Solution: %.9f\n\n", p);

    // Aitken's Method
    printf("Aitken's Δ² Acceleration Method:\n");

    // Initializing variables for Aitken's Method
    double p_n = p0;         // p_n
    double p_n1;             // p_{n+1}
    double p_n2;             // p_{n+2}
    double aitken_p;         // Accelerated value
    int aitken_iterations = 0;

    while (1) {
        // Compute three consecutive terms of the sequence
        p_n1 = p_n - (f(p_n) / derivative(p_n));
        p_n2 = p_n1 - (f(p_n1) / derivative(p_n1));

        // Aitken's formula
        aitken_p = p_n - pow((p_n1 - p_n), 2) / (p_n2 - 2 * p_n1 + p_n);

        // Print the current iteration
        printf("Iteration %d: Aitken_p = %.9f\n", aitken_iterations + 1, aitken_p);

        // Check for convergence
        if (fabs(aitken_p - p_n) < tolerance) {
            break;
        }

        // Update for the next iteration
        p_n = aitken_p;
        aitken_iterations++;
    }

    printf("Aitken's Method Success after %d iterations\n", aitken_iterations + 1);
    printf("Solution: %.9f\n", aitken_p);

    return 0;
}
