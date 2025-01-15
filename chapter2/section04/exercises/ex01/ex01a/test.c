#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x * x - 2 * x * exp(-x) + exp(-2 * x);
}

// Define the first derivative f'(x)
double f_prime(double x) {
    return 2 * x - 2 * exp(-x) + 2 * x * exp(-x);
}

// Define the second derivative f''(x)
double f_double_prime(double x) {
    return 2 - 2 * exp(-x) + 2 * exp(-x) + 2 * x * exp(-x);
}

// Modified Newton Method
void modified_newton_method(double initial_guess, double tolerance, int max_iterations) {
    double x = initial_guess;
    int iteration = 0;

    printf("Iter\t x\t\t f(x)\n");
    while (iteration < max_iterations) {
        double f_value = f(x);
        double f_prime_value = f_prime(x);
        double f_double_prime_value = f_double_prime(x);

        printf("%d\t %.10f\t %.10f\n", iteration, x, f_value);

        if (fabs(f_value) < tolerance) { // Check for convergence
            printf("Root found at x = %.10f\n", x);
            return;
        }

        // Update x using Modified Newton formula
        double denominator = f_prime_value * f_prime_value - f_value * f_double_prime_value;
        if (fabs(denominator) < 1e-12) { // Prevent division by zero or instability
            printf("Denominator too small, stopping.\n");
            return;
        }
        x = x - (f_value * f_prime_value / denominator);

        iteration++;
    }

    printf("Maximum iterations reached. Last x = %.10f\n", x);
}

int main() {
    double initial_guess = 0.5;  // Initial guess
    double tolerance = 1e-5;     // Convergence tolerance (5 digits of accuracy)
    int max_iterations = 100;   // Maximum number of iterations

    printf("Modified Newton Method:\n");
    modified_newton_method(initial_guess, tolerance, max_iterations);

    return 0;
}
