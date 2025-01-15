# Proof that \( \frac{1}{n^2} \) is not linearly convergent

To prove that the sequence \( \frac{1}{n^2} \) is **not** linearly convergent, we need to show that it does not satisfy the inequality for linear convergence:

$$
|x_{n+1} + L| \leq C \cdot |x_n + L| \quad \text{with} \quad C < 1.
$$

Here, \( x_n = \frac{1}{n^2} \) and the sequence converges to \( L = 0 \). Thus, the inequality becomes:

$$
\left| \frac{1}{(n+1)^2} \right| \leq C \cdot \left| \frac{1}{n^2} \right|
$$

Multiplying both sides by \( n^2 \), we have:

$$
\frac{n^2}{(n+1)^2} \leq C
$$

Simplify \( \frac{n^2}{(n+1)^2} \):

$$
\frac{n^2}{(n+1)^2} = \frac{n^2}{n^2 + 2n + 1}.
$$

As \( n \to \infty \), the fraction approaches:

$$
\frac{n^2}{n^2 + 2n + 1} \approx 1 - \frac{2}{n} + \frac{1}{n^2}.
$$

For large \( n \), this value approaches 1, which implies that \( C \geq 1 \). Since \( C < 1 \) is required for linear convergence, the sequence does not satisfy the condition for linear convergence.

---

**Conclusion**: The sequence $\( \ frac{1}{n^2} \)$ is **not** linearly convergent because it converges too quickly for a constant \( C < 1 \) to exist that satisfies the inequality.
