# Numerical Methods for Finding Roots

## Newton's Method

Newton's Method, also known as the Newton-Raphson method, is an iterative technique for finding the roots of a real-valued function. The method uses the function's derivative to approximate the root. The formula for Newton's Method is:

\[ x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)} \]

where:

- \( x_n \) is the current approximation,
- \( f(x_n) \) is the function value at \( x_n \),
- \( f'(x_n) \) is the derivative of the function at \( x_n \).

The process is repeated until a sufficiently accurate value is found.

## Secant Method

The Secant Method is similar to Newton's Method but does not require the calculation of the derivative. Instead, it uses a secant line through two points on the function to approximate the root. The formula for the Secant Method is:

\[ x_{n+1} = x_n - f(x_n) \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})} \]

where:

- \( x_n \) and \( x_{n-1} \) are the current and previous approximations,
- \( f(x_n) \) and \( f(x_{n-1}) \) are the function values at \( x_n \) and \( x_{n-1} \).

The method iterates until convergence.

## False Position Method

The False Position Method, also known as the Regula Falsi method, is a bracketing method that combines the ideas of the bisection method and the secant method. It uses a linear interpolation to find the root. The formula for the False Position Method is:

\[ x_{n+1} = x_n - f(x_n) \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})} \]

However, unlike the Secant Method, the False Position Method ensures that the root is always bracketed by updating the interval endpoints based on the sign of the function values.

The process continues until the root is found within a desired tolerance.

## Exercises

Exercises showing and explaining the usage of each method can be found [here](exercises/)