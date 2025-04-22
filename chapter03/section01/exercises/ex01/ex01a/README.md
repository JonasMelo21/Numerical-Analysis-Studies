# Exercise 01 A

We have to find first and second degree Lagrange Interpolating Linear Polynomial for $f(x) = cos(x)$ with $x_{0} = 0, x_{1} = 0.6 ,  x_{2} = 0.9$

First, let's remember the general form of Lagrange Linear Interpolating Polynomial for any degree $n$:

$$
P(x) = \sum_{k = 0}^{n} f(x_{k}) \cdot L_{k}(x)
$$

$$
L_{k}(x) = \prod_{i=0, i \neq k}^{n} \frac{(x - x_{i})}{x_{k} - x_{i}}
$$

## First Degree Polynomial (N = 1)

The form of the polynomial with degree 1 will be:

$$
P(x) = f(x_{0}) \cdot L_{0}(x) + f(x_{1}) \cdot L_{1}(x)
$$

As $f(x_{0}) = cos(x_{0}) = cos(0) = 1$ and $f(x_{1}) = cos(x_{1}) = cos(0.6) = 0.82$ we have:

$$
P(x) = 1 \cdot L_{0}(x) + 0.82 \cdot L_{1}(x)
$$

Now, let's find $L_{0}$ and $L_{1}$ given that:

$$
L_{k}(x) = \prod_{i=0, i \neq k}^{n} \frac{(x - x_{i})}{x_{k} - x_{i}}
$$

For $k = 0$ and $n = 1$:

$$
L_{0} = \frac{(x - x_{1})}{x_{0} - x_{1}} = \frac{(x - 0.6)}{(0 - 0.6)} = \frac{(x - 0.6)}{-0.6} = \frac{(0.6 - x)}{0.6} = 1 - \frac{x}{0.6}
$$

$$
\boxed{L_{0} = 1 - \frac{x}{0.6}}
$$