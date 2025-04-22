# Interpolation and the Lagrange Polynomial

This repository explores **interpolation methods**, particularly the **Lagrange Polynomial**, as discussed in *Numerical Analysis (9th Edition)* by Richard L. Burden. The goal is to approximate functions or datasets using polynomials that pass through given points.

---

## 1. Introduction to Interpolation
Interpolation is a method of constructing new data points within the range of a known set of data points. Given a set of $(n+1)$ data points $(x_i, y_i)$, where $x_i$ are distinct, we seek a polynomial $P(x)$ such that:

$$
P(x_i) = y_i \quad \text{for} \quad i = 0, 1, \dots, n.
$$

---

## 2. The Lagrange Interpolating Polynomial
The **Lagrange Polynomial** is a popular choice for interpolation. For $(n+1)$ points, the polynomial $P_n(x)$ of degree $\leq n$ is given by:

$$
P_n(x) = \sum_{k=0}^n y_k L_{k}(x),
$$

where $L_{k}(x)$ are the **Lagrange basis polynomials**, defined as:

$$
L_k(x) = \prod_{\substack{i=0 \\ i \neq k}}^n \frac{x - x_i}{x_k - x_i}.
$$

### Properties:
- **Existence & Uniqueness**: Only one polynomial of degree $\leq n$ interpolates the given data.
- **Accuracy**: The error depends on the function smoothness and node distribution.

---

## 3. Example
Given points $(1, 2)$, $(2, 3)$, and $(4, 0)$, the Lagrange Polynomial is:

$$
P_2(x) = 2 \cdot \frac{(x-2)(x-4)}{(1-2)(1-4)} + 3 \cdot \frac{(x-1)(x-4)}{(2-1)(2-4)} + 0 \cdot \frac{(x-1)(x-2)}{(4-1)(4-2)}.
$$

Simplifying:

$$
P_2(x) = \frac{2}{3}(x-2)(x-4) - \frac{3}{2}(x-1)(x-4).
$$

---

## 4. Error Analysis
The interpolation error for a function $f(x)$ at a point $x$ is:

$$
f(x) - P_n(x) = \frac{f^{(n+1)}(\xi)}{(n+1)!} \prod_{i=0}^n (x - x_i),
$$

where $x_{i}$ lies in the interval containing $x_0, x_1, \dots, x_n$ and $x$.

---

## 5. Implementations
This repository includes:
- Python code for computing the Lagrange Polynomial.
- Numerical examples from Burden's book.
- Error analysis comparisons.

---

## References
- Burden, R. L., & Faires, J. D. (2011). *Numerical Analysis* (9th ed.). Cengage Learning.

---

**Note**: GitHub supports MathJax rendering in Markdown. For best results, view this file on GitHub or with a MathJax-compatible viewer.

# Exercises:

the exercises of this section can be found [clicking here](exercises/)
