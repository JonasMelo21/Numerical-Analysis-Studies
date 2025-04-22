# Letter B Solution

## Proof that $\( \frac{1}{n^2} \)$ is  linearly convergent

To prove that the sequence $\( \frac{1}{n^2} \)$ is linearly convergent, we need to show that it does not satisfy the inequality for linear convergence:

$$
|x_{n+1} + L| \leq C \cdot |x_n + L| \quad \text{with} \quad C < 1.
$$

Here, $\( x_n = \frac{1}{n^2} \)$ and the sequence converges to $\( L = 0 \)$. Thus, the inequality becomes:

$$
\left| \frac{1}{(n+1)^2} \right| \leq C \cdot \left| \frac{1}{n^2} \right|
$$

Multiplying both sides by $\( n^2 \)$, we have:

$$
\frac{n^2}{(n+1)^2} \leq C
$$

Taking the square root on both sides:

$$
\frac{\sqrt{n^2}}{\sqrt{(n+1)^2}} = \frac{n}{n + 1} \leq \sqrt{C}.
$$

Which will raise a positive number less than 1. If $\frac{n}{n + 1}$ < 1, then C < 1.

**Conclusion**: The sequence $\( \frac{1}{n^2} \)$ is linearly convergent.

## How many iteractions to guarantee $\ |p_{n} - p| \leq 5 \cdot$

$$
\frac{1}{n^2} \leq 5 \cdot 10^{(-2)}
$$

$$
\frac{1}{5 \cdot 10^{(-2)}} \leq n^{2}
$$

$$
20 \leq n^{2}
$$

$$
2 \cdot \sqrt{5} \leq n
$$
