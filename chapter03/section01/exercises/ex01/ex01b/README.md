# Exercise 01 B

We want to find the first and second degree linear lagrange interpolating polynomial for the function $ f(x) = \sqrt{1+x}$

The general form of a Linear Lagrange Interpolating Polynomial of degree n is:

$$
P(x) = \sum_{k = 0}^{n} f(x_{k}) \cdot L_{k}(x)
$$

$$
L_{k}(x) = \prod_{i = 0,i \neq k}^{n} \frac{(x - x_{i})}{(x_{k} - x_{i})}
$$

## First Degree Polynomial( N = 1):

$$
P(x) = f(x_{0}) \cdot L_{0}(x) + f(x_{1}) \cdot L_{1}(x)
$$

$$
P(x) = \sqrt{1 + 0} \cdot L_{0}(x) + \sqrt{1 + 0.6} \cdot L_{1}(x)
$$

$$
P(x) = L_{0}(x) + \sqrt{1.6} \cdot L_{1}(x)
$$

$$
P(x) = L_{0}(x) + 1.264 \cdot L_{1}(x)
$$

$$
P(x) = L_{0}(x) + 1.264 \cdot L_{1}(x)
$$

### Let's Find $L_{0}(x)$ and $L_{1}(x)$:

As the genral form of L_{k}(x) is:

$$
L_{k}(x) = \prod_{i = 0,i \neq k}^{n} \frac{(x - x_{i})}{(x_{k} - x_{i})}
$$

We have:

For $k = 0 \rightarrow L_{0}(x)$:

$$
L_{0}(x) = \frac{(x - x_{1})}{(x_{0} - x_{1})} = \frac{(x - 0.6)}{(0 - 0.6)} = 1 - \frac{x}{0.6}
$$

Notice that L_{0}(x) is the same for the one we found in exercise 1 letter a. So:

$$
L_{1}(x)= \frac{x}{0.6}
$$

So $1^{st}$ degree polynomial is:

$$
P(x) = 1 \cdot (1 - \frac{x}{0.6}) + 1.264 \cdot (\frac{x}{0.6})
$$

$$
P(x) =  1 - \frac{x}{0.6} + 1.264 \cdot (\frac{x}{0.6})
$$

$$
P(x) = 1 + 0.264 \cdot \frac{x}{0.6}
$$

$$
P(x) = 1 + 0.44 \cdot x
$$

### Evaluating P(x) for x = 0.45

$$
P(0.45) = 1 + 0.44 \cdot 0.45 = 1 + 0.198 = 1.198
$$

### Absolute Error

$$
P(x) = | 1.198 - 1,2 | \approx 0.002
$$

## Second Degree Polynomial (N = 2):
