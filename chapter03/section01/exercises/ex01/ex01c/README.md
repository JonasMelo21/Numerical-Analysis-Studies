# Exercise 01 B

We want to find the first- and second-degree Lagrange interpolating polynomials for the function:

$$
f(x) = \sqrt{1+x}
$$

The general form of the Lagrange interpolating polynomial of degree \( n \) is:

$$
P(x) = \sum_{k = 0}^{n} f(x_k) \cdot L_k(x)
$$

Where each Lagrange basis polynomial \( L_k(x) \) is defined as:

$$
L_k(x) = \prod_{\substack{i=0 \\ i \neq k}}^{n} \frac{x - x_i}{x_k - x_i}
$$

---

## First-Degree Polynomial ( \( N = 1 \) )

We choose the points:
- \( x_0 = 0 \Rightarrow f(x_0) = \sqrt{1 + 0} = 1 \)
- \( x_1 = 0.6 \Rightarrow f(x_1) = \sqrt{1 + 0.6} \approx 1.2649 \)

### Lagrange Basis Polynomials:
\[
L_0(x) = \frac{x - 0.6}{0 - 0.6} = \frac{x - 0.6}{-0.6} = 1 - \frac{x}{0.6}
\]
\[
L_1(x) = \frac{x - 0}{0.6 - 0} = \frac{x}{0.6}
\]

### First-degree interpolation polynomial:
\[
P_1(x) = 1 \cdot \left(1 - \frac{x}{0.6}\right) + 1.2649 \cdot \left(\frac{x}{0.6}\right)
\]
\[
P_1(x) = 1 - \frac{x}{0.6} + 1.2649 \cdot \frac{x}{0.6}
\]
\[
P_1(x) = 1 + (1.2649 - 1) \cdot \frac{x}{0.6} = 1 + 0.2649 \cdot \frac{x}{0.6}
\]
\[
P_1(x) = 1 + 0.4415 \cdot x
\]

### Evaluating \( P_1(0.45) \):
\[
P_1(0.45) = 1 + 0.4415 \cdot 0.45 = 1 + 0.1987 = 1.1987
\]

### Absolute Error (compared to true value \( \sqrt{1.45} \approx 1.2042 \)):
\[
\text{Error} = |1.1987 - 1.2042| \approx 0.0055
\]

---

## Second-Degree Polynomial ( \( N = 2 \) )

We add a third point:
- \( x_2 = 0.9 \Rightarrow f(x_2) = \sqrt{1 + 0.9} = \sqrt{1.9} \approx 1.3784 \)

### Lagrange Basis Polynomials:

\[
L_0(x) = \frac{(x - 0.6)(x - 0.9)}{(0 - 0.6)(0 - 0.9)} = \frac{(x - 0.6)(x - 0.9)}{0.54}
\]

\[
L_1(x) = \frac{(x - 0)(x - 0.9)}{(0.6 - 0)(0.6 - 0.9)} = \frac{x(x - 0.9)}{-0.18}
\]

\[
L_2(x) = \frac{(x - 0)(x - 0.6)}{(0.9 - 0)(0.9 - 0.6)} = \frac{x(x - 0.6)}{0.27}
\]

### Second-degree polynomial:
\[
P_2(x) = 1 \cdot L_0(x) + 1.2649 \cdot L_1(x) + 1.3784 \cdot L_2(x)
\]

Substituting the values:

\[
P_2(x) = \frac{(x - 0.6)(x - 0.9)}{0.54} - 1.2649 \cdot \frac{x(x - 0.9)}{0.18} + 1.3784 \cdot \frac{x(x - 0.6)}{0.27}
\]

### Evaluating \( P_2(0.45) \):

We'll compute this step-by-step:

- \( L_0(0.45) = \frac{(0.45 - 0.6)(0.45 - 0.9)}{0.54} = \frac{(-0.15)(-0.45)}{0.54} = \frac{0.0675}{0.54} \approx 0.125 \)
- \( L_1(0.45) = \frac{(0.45)(0.45 - 0.9)}{-0.18} = \frac{(0.45)(-0.45)}{-0.18} = \frac{-0.2025}{-0.18} \approx 1.125 \)
- \( L_2(0.45) = \frac{(0.45)(0.45 - 0.6)}{0.27} = \frac{(0.45)(-0.15)}{0.27} = \frac{-0.0675}{0.27} \approx -0.25 \)

Now plug in:

\[
P_2(0.45) = 1 \cdot 0.125 + 1.2649 \cdot 1.125 + 1.3784 \cdot (-0.25)
\]
\[
P_2(0.45) = 0.125 + 1.4230 - 0.3446 = 1.2034
\]

### Absolute Error:
\[
\text{Error} = |1.2034 - 1.2042| \approx 0.0008
\]

---

## Final Results:

| Degree | Polynomial Value at \(x = 0.45\) | True Value \( \sqrt{1.45} \) | Absolute Error |
|--------|-------------------------------|-------------------------------|----------------|
| 1st    | 1.1987                        | 1.2042                        | 0.0055         |
| 2nd    | 1.2034                        | 1.2042                        | 0.0008         |
