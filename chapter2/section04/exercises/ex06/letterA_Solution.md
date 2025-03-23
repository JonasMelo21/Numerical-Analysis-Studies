# Exercise 06 - Letter A


## Prove that Pn = (1 / n) is linearly convergent
To prove that a sequence is linearly independent, we have to ensure that:

$$
|x_{n+1} + L| \leq C \cdot |x_n + L|
$$

where \(x_n \) is the \( n-th \) term of the sequence, \( L \) is the value for which the sequence converges, and \( C \) is a positive constant less than 1 (\( C < 1 \)).

The value of \( L \) is:

$$
\lim_{n \to \infty} \frac{1}{n} = 0
$$

Therefore, it gives us:

$$
\left| \frac{1}{n+1} \right| \leq C \cdot \left| \frac{1}{n} \right|
$$

Multiplying both sides by \( n \), we have:

$$
\left| \frac{n}{n+1} \right| \leq C
$$

But for every positive number \( n \), if divided by a number greater than itself, the result will be a number greater than 0 and less than 1. Thus:

$$
\left| \frac{n}{n+1} \right| \leq 1 \leq C \quad \Rightarrow \quad C < 1
$$

That's it, we've proven that the sequence is linearly convergent.

## How many iteractions to guarantee $|  pn - p \ |$ < 0.05 ?

$$
| \ p_{n} - p\ | \leq 0.05
$$

$$
| \frac{1}{n} \ | \leq 0.05 
$$

$$ 
| \frac{1}{0.05} \ | \leq n
$$

$$
| 20  | \leq n
$$

**Conclusions:** 
That shows us we would need at least 20 iteractions
