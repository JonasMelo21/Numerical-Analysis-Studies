Sure! Here's the corrected and polished version of your Lagrange Interpolation solution in **MathJax Markdown** and in **English**:

---

# Exercise 01 D

We are asked to build the **1st** and **2nd degree Linear Lagrange Interpolating Polynomials** for the function  
$f(x) = \tan(x)$,  
using the nodes $x_0 = 0$,$x_1 = 0.6$, and $x_2 = 0.9$.

---

## General Formula for Lagrange Interpolating Polynomials

$$
P(x) = \sum_{k = 0}^{n} f(x_k) \cdot L_k(x)
$$

Where the Lagrange basis polynomial is defined as:

$$
L_k(x) = \prod_{i = 0,i \neq k}^{n} \frac{x - x_{i}}{x_{k} - x_{i}}
$$

---

## 1st-Degree Interpolation Polynomial (Linear)

We consider $x_0 = 0$and$x_1 = 0.6$.  
Then,

$$
L_0(x) = \frac{x - 0.6}{0 - 0.6} = \frac{x - 0.6}{-0.6} = 1 - \frac{x}{0.6}
$$

$$
L_1(x) = \frac{x - 0}{0.6 - 0} = \frac{x}{0.6}
$$

Evaluating the function at these points:

$$
f(x_0) = \tan(0) = 0
$$
$$
f(x_1) = \tan(0.6) \approx 0.684
$$

So the interpolating polynomial is:

$$
P_1(x) = f(x_0) \cdot L_0(x) + f(x_1) \cdot L_1(x)
$$
$$
P_1(x) = 0 + 0.684 \cdot \frac{x}{0.6}
$$
$$
P_1(x) = 1.14x
$$

### Evaluation at$x = 0.45$:

$$
P_1(0.45) = 1.14 \cdot 0.45 = 0.513
$$
$$
f(0.45) = \tan(0.45) \approx 0.480
$$

**Absolute Error**:

$$
|P_1(0.45) - f(0.45)| = |0.513 - 0.480| = 0.033
$$

---

## 2nd-Degree Interpolation Polynomial (Quadratic)

Now include $x_2 = 0.9$.  
Lagrange basis terms:

$$
L_0(x) = \frac{(x - 0.6)(x - 0.9)}{(0 - 0.6)(0 - 0.9)} = \frac{(x - 0.6)(x - 0.9)}{0.54}
$$

$$
L_1(x) = \frac{(x - 0)(x - 0.9)}{(0.6 - 0)(0.6 - 0.9)} = \frac{x(x - 0.9)}{-0.18}
$$

$$
L_2(x) = \frac{(x - 0)(x - 0.6)}{(0.9 - 0)(0.9 - 0.6)} = \frac{x(x - 0.6)}{0.27}
$$

Function values:

$$
f(x_0) = \tan(0) = 0, \quad f(x_1) = \tan(0.6) \approx 0.684, \quad f(x_2) = \tan(0.9) \approx 1.260
$$

Interpolating polynomial:

$$
P_2(x) = 0 \cdot L_0(x) + 0.684 \cdot L_1(x) + 1.260 \cdot L_2(x)
$$

$$
P_2(x) = 0.684 \cdot \frac{x(x - 0.9)}{-0.18} + 1.260 \cdot \frac{x(x - 0.6)}{0.27}
$$

---

### Evaluation at$x = 0.45$:

$$
P_2(0.45) = 0.684 \cdot \frac{0.45 \cdot (0.45 - 0.9)}{-0.18} + 1.260 \cdot \frac{0.45 \cdot (0.45 - 0.6)}{0.27}
$$

$$
P_2(0.45) = 0.684 \cdot \frac{0.45 \cdot (-0.45)}{-0.18} + 1.260 \cdot \frac{0.45 \cdot (-0.15)}{0.27}
$$

$$
P_2(0.45) = 0.684 \cdot \frac{-0.2025}{-0.18} + 1.260 \cdot \frac{-0.0675}{0.27}
$$

$$
P_2(0.45) = 0.684 \cdot 1.125 + 1.260 \cdot (-0.25)
$$

$$
P_2(0.45) = 0.7695 - 0.315 = 0.4545
$$

$$
f(0.45) = \tan(0.45) \approx 0.480
$$

**Absolute Error**:

$$
|P_2(0.45) - f(0.45)| = |0.4545 - 0.480| = 0.0255
$$

---

## Summary

- **1st-degree interpolation**:  
$P_1(0.45) = 0.513$, error ≈ **0.033**

- **2nd-degree interpolation**:  
$P_2(0.45) = 0.4545$, error ≈ **0.0255**

The 2nd-degree polynomial yields a more accurate approximation of $\tan(0.45)$.