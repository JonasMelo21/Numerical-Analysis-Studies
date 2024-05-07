# Taylor Polynomial for Natural Logarithm Series

## Introduction

The Nth term of the Taylor Polynomial for the Natural Logarithm( log(x) ) is:

        Pn(x) = (símbolo sigma que vai de i = 1 até n) = (-1)^(i+1) / i * (x - 1) ^(i)

Let's construct an algorithm to determine the minimal value of N required for tolerance = 0.00001:
        |log(x) - Pn(x)| < 0.00001

From calculus, we know Pn(x) for log(x) function is an alternative series with limit A which terms decrease in magnitude when n increases.Which means, the A(n + 1)th is less than the A(n)th term. So the difference between the limit A and a A(n)th is always bigger than A(n + 1)th term.That is:

        |A - An| <= |A(n + 1)|

The [following algorithm](https://github.com/JonasMelo21/Numerical-Analysis-Studies/blob/9d0573f8ad11bc3f8acdcc9c9d080cad58536b4a/chapter1/TaylorPolynomials-NaturalLogarithm/naturalLogTaylorSeries.c) uses this bound for x = 1.5 and tolerance = 0.00001.