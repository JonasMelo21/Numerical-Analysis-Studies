
# Exercise 01 A

We have to find first and second degree Lagrange Interpolating Linear Polynomial for $f(x) = \cos(x)$ with $x_{0} = 0, x_{1} = 0.6 ,  x_{2} = 0.9$

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

As $f(x_{0}) = \cos(x_{0}) = \cos(0) = 1$ and $f(x_{1}) = \cos(x_{1}) = \cos(0.6) = 0.82$ we have:

$$
P(x) = 1 \cdot L_{0}(x) + 0.82 \cdot L_{1}(x)
$$

Now, let's find $L_{0}$ and $L_{1}$ given that:

$$
L_{k}(x) = \prod_{i=0, i \neq k}^{n} \frac{(x - x_{i})}{x_{k} - x_{i}}
$$

For $k = 0$ and $n = 1$:

$$
L_{0}(x) = \frac{(x - x_{1})}{x_{0} - x_{1}} = \frac{(x - 0.6)}{(0 - 0.6)} = \frac{(x - 0.6)}{-0.6} = \frac{(0.6 - x)}{0.6} = 1 - \frac{x}{0.6}
$$

$$
L_{0}(x) = 1 - \frac{x}{0.6}
$$

Now, for $k = 1$:

$$
L_{1}(x) = \frac{(x - x_{0})}{(x_{1} - x_{0})} = \frac{x}{0.6}
$$

Returning to the Polynomial Equation:

$$
P(x) = 1 \cdot L_{0}(x) + 0.82 \cdot L_{1}(x)
$$

As $L_{0}(x) = 1 - \frac{x}{0.6}$ and $L_{1}(x) = \frac{x}{0.6}$:

$$
P(x) = 1 \cdot (1 - \frac{x}{0.6}) + 0.82 \cdot (\frac{x}{0.6})
$$

$$
P(x) = 1 - 0.3 \cdot x
$$

The value for the polynomial evaluated at $x = 0.45$ is:

$$
P(x) = 1 - 0.3 \cdot (0.45) = 1 - 0.135 = 0.865
$$

As $\cos(0.45) = 0.9$ , the absolute error is:

$$
Error = | \cos(0.45) - P(0.45) | = | 0.9 - 0.865 | \approx 0.035
$$

---

## Second Degree Polynomial (N = 2)

The general form for the degree 2 Lagrange Interpolating Polynomial is:

$$
P(x) = f(x_0) \cdot L_0(x) + f(x_1) \cdot L_1(x) + f(x_2) \cdot L_2(x)
$$

We already know:
- $x_0 = 0 \Rightarrow f(x_0) = \cos(0) = 1$
- $x_1 = 0.6 \Rightarrow f(x_1) = \cos(0.6) \approx 0.8253$
- $x_2 = 0.9 \Rightarrow f(x_2) = \cos(0.9) \approx 0.6216$

### Step 1: Compute the Lagrange basis polynomials

#### $L_0(x)$:

$$
L_0(x) = \frac{(x - 0.6)(x - 0.9)}{0.54}
$$

#### $L_1(x)$:

$$
L_1(x) = \frac{x(x - 0.9)}{-0.18}
$$

#### $L_2(x)$:

$$
L_2(x) = \frac{x(x - 0.6)}{0.27}
$$

### Step 2: Form the interpolating polynomial

Using the approximated values:

- $f(x_0) = 1$
- $f(x_1) \approx 0.8253$
- $f(x_2) \approx 0.6216$

So:

$$
P(x) = 1 \cdot \frac{(x - 0.6)(x - 0.9)}{0.54} + 0.8253 \cdot \frac{x(x - 0.9)}{-0.18} + 0.6216 \cdot \frac{x(x - 0.6)}{0.27}
$$

### Step 3: Evaluate $P(x)$ at $x = 0.45$

- $L_0(0.45) \approx 0.125$
- $L_1(0.45) \approx 1.125$
- $L_2(0.45) \approx -0.25$

Substitute into the polynomial:

$$
P(0.45) = 1 \cdot 0.125 + 0.8253 \cdot 1.125 + 0.6216 \cdot (-0.25)
$$

$$
P(0.45) \approx 0.125 + 0.9285 - 0.1554 = 0.8981
$$

### Step 4: Absolute Error

Compare with $\cos(0.45) \approx 0.9004$:

$$
Error = | \cos(0.45) - P(0.45) | = | 0.9004 - 0.8981 | \approx 0.0023
$$

### ✅ Conclusion

The second-degree Lagrange interpolating polynomial provides a much more accurate approximation (error ~0.0023) than the first-degree one (error ~0.035).
