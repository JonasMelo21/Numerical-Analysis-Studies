<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

## Introduction

The Nth term of the Taylor Polynomial for the Natural Logarithm (\( \log(x) \)) is given by the formula:

\[ P_n(x) = \sum_{i=1}^{n} \frac{(-1)^{i+1}}{i} \cdot (x - 1)^{i} \]

Let's construct an algorithm to determine the minimal value of \( N \) required for a given tolerance \( \epsilon = 0.00001 \):

\[ |\log(x) - P_n(x)| < 0.00001 \]

From calculus, we know that \( P_n(x) \) for the \( \log(x) \) function is an alternating series with limit \( A \), and its terms decrease in magnitude as \( n \) increases. This implies that the \( (n + 1) \)th term is less than the \( n \)th term. Therefore, the difference between the limit \( A \) and the \( N \)th partial sum \( A_N \) is always greater than the magnitude of the \( (N + 1) \)th term. Mathematically:

\[ |A - A_N| \leq |A_{(N + 1)}| \]

The [following algorithm](https://github.com/JonasMelo21/Numerical-Analysis-Studies/blob/9d0573f8ad11bc3f8acdcc9c9d080cad58536b4a/chapter1/TaylorPolynomials-NaturalLogarithm/naturalLogTaylorSeries.c) utilizes this bound for \( x = 1.5 \) and \( \epsilon = 0.00001 \).
