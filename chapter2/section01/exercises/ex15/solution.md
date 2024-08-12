## Estimation of the Number of Iterations Required Using the Bisection Method

We want to find the root of the equation \( x^3 + x - 4 = 0 \) with a precision of \( 10^{-3} = 0.001 \) using the bisection method within the interval \([1,4]\).

### Step-by-Step:

Let:
- \( a = 1 \)
- \( b = 2 \)
- \( p \) be the root
- \( p_n \) be the \( n \)-th term such that \( p_n \) is the approximation of \( p \) after \( n \) iterations.

According to the bisection method:

\[
p_n - p \leq \frac{b - a}{2^{n-1}}
\]

Substituting the values of \( a \) and \( b \):

\[
\frac{2 - 1}{2^{n-1}} \leq 10^{-3}
\]

This simplifies to:

\[
\frac{1}{2^{n-1}} \leq 0.001
\]

We need to solve for \( n \):

\[
2^{n-1} \geq 1000
\]

Taking the logarithm on both sides:

\[
n - 1 \geq \log_2(1000)
\]

Calculating:

\[
n \geq \log_2(1000) + 1
\]

\[
n  \approx 14
\]

### Conclusion:

Thus, **13 iterations** are required to achieve the desired precision using the bisection method within the interval \([1, 4]\).
## Estimation of the Number of Iterations Required Using the Bisection Method

We want to find the root of the equation \( x^3 + x - 4 = 0 \) with a precision of \( 10^{-3} = 0.001 \) using the bisection method within the interval \([1,4]\).

### Step-by-Step:

Let:
- \( a = 1 \)
- \( b = 4 \)
- \( p \) be the root
- \( p_n \) be the \( n \)-th term such that \( p_n \) is the approximation of \( p \) after \( n \) iterations.

According to the bisection method:

\[
p_n - p \leq \frac{b - a}{2^{n-1}}
\]

Substituting the values of \( a \) and \( b \):

\[
\frac{4 - 1}{2^{n-1}} \leq 10^{-3}
\]

This simplifies to:

\[
\frac{3}{2^{n-1}} \leq 0.001
\]

We need to solve for \( n \):

\[
2^{n-1} \geq 3000
\]

Taking the logarithm on both sides:

\[
n - 1 \geq \log_2(3000)
\]

Calculating:

\[
n \geq \log_2(3000) + 1
\]

\[
n \approx 12.55 + 1 \approx 13
\]

### Conclusion:

Thus, **13 iterations** are required to achieve the desired precision using the bisection method within the interval \([1, 4]\).
