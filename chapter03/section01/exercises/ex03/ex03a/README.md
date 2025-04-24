# Exercise 03 A

## Introduction

The question wants us to find an error bound for:

$$f(x) = \cos(x)$$
$$x_{0} = 0$$
$$x_{1} = 0.6$$
$$x_{2} = 0.9$$

For $N = 1$ and $N = 2$.

Acording to theorem 3.3 the error bound for lagrange interpolating polynomial has the form:

$$Error_{n}(x) = \frac{f^{(n+1)}(\epsilon(x))}{(n + 1)!} \cdot \prod_{i = 0}^{n} (x - x_{i})$$

## Finding Error Bound for N = 1, $f(x) = \cos(x)$, $f''(x) = - \cos(x)$ and $x = 0.45$:

$$Error_{1}(0.45) = | \frac{f^{''}(\epsilon(0.45))}{(1 + 1)!} | \cdot | (0.45 - 0) \cdot (0.45 - 0.6) |$$


The ma0.45 value of $\cos(0.45)$ in the interval $[0,0.6]$ is $\cos(0) = 1$. So $\epsilon(0.45) = 0$:
---
$$Error_{1}(0.45) = | \frac{\cos(0)}{2!} | \cdot | (0.45 - 0) \cdot (0.45 - 0.6) |$$

$$Error_{1}(0.45) = | \frac{1}{2} | \cdot | (0.45) \cdot (-0.15) |$$

$$Error_{1}(0.45) = | \frac{1}{2} | \cdot | -0.0675 |$$

$$Error_{1}(0.45) = | -0.03375 | = 0.03375$$

## Finding the Error Bound for $N = 2$, $f(x) = \cos(x)$, $f'''(x) = \sin(x)$, $x = 0.45$ and same values for $x_{0},  x_{1},  x_{2}$:

$$Error_{2}(0.45) = | \frac{f'''(\epsilon(0.45))}{(2 + 1)!} | | \cdot (x - _{0}) \cdot (x - x_{1}) \cdot (x - x_{2}) |$$

$$Error_{2}(0.45) = | \frac{\sin(\epsilon(x))}{3!} | | \cdot (x) \cdot (x - 0.6) \cdot (x - 0.9) |$$

The maximum value for the function $\sin(x)$ within the interval $[0,0.9]$ is $\sin(0.9) = 0.78$. So $\epsilon(x) = 0.78$:

$$Error_{2}(0.45) = | \frac{\sin(0.9)}{6} | \cdot | 0.45 \cdot (0.45 - 0.6) \cdot (0.45 - 0.9) | $$

$$ Error_{2}(0.45) = | \frac{0.78}{6} | \cdot | 0.030375 |$$

$$ Error_{2}(0.45) = | 0.13 \cdot 0.03 | = | 0.003 | $$

## Conclusion:

The polynomial gets more accurate with higher degrees. Since $Error_{1}(0.45) = 0.03 < Error_{2}(0.45) = 0.003$.