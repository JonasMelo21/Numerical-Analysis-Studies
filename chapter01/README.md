# Chapter 1: Mathematical Preliminaries and Error Analysis

This chapter introduces foundational concepts for numerical analysis, including **floating-point arithmetic**, **error types**, and **stability algorithms**, as presented in *Numerical Analysis (9th Ed.)* by Burden & Faires.

---

## 📖 Sections Summary

### [1.1 Review of Calculus](section01/)
Key theorems from calculus essential for error analysis:
- **Taylor’s Theorem**:  
For $f \in C^{n+1}[a, b]$ and $x_0 \in [a, b]$, the Taylor polynomial approximation is:

$$ f(x) = P_n(x) + R_n(x), \quad \text{where} \quad P_n(x) = \sum_{k=0}^n \frac{f^{(k)}(x_0)}{k!}(x - x_0)^k, $$

and the remainder term is:

$$ 
R_n(x) = \frac{f^{(n+1)}(\xi)}{(n+1)!}(x - x_0)^{n+1}, \quad \xi \in (x_0, x).
$$

### [1.2 Roundoff Errors and Truncation](section02/)
- **Roundoff Errors**: Caused by finite-digit representation (e.g., IEEE 754).  
Example: Floating-point representation $x = \pm 0.d_1d_2 \dots d_k \times 10^n$.
- **Truncation Errors**: Result from approximating infinite processes (e.g., series truncation).

### [1.3 Algorithms and Convergence](section03/)
- **Algorithm Stability**: Sensitive vs. insensitive to small errors.  
- **Rate of Convergence**: For a sequence $\{x_n\}$ converging to $x^*$, if $\exists  \lambda > 0$ such that:


$$
\lim_{n \to \infty} \frac{|x_{n+1} - x|}{|x_n - x|} = \lambda
$$


then $\lambda$ is the **asymptotic error constant**.

### [1.4 Numerical Software](section04/)
- Tools: MATLAB, C  
- Best practices: Avoid catastrophic cancellation, use built-in libraries for stability.

---

## 🔍 Key Concepts
| Term               | Definition                                                                 |
|--------------------|---------------------------------------------------------------------------|
| **Absolute Error** | $|x - \hat{x}|$ where $x$ is exact, $\hat{x}$ is approximation.          |
| **Relative Error** | $\frac{|x - \hat{x}|}{|x|}$ (if $x \neq 0$).                              |
| **Machine Epsilon** | Smallest $\epsilon$ such that $1 + \epsilon > 1$ in floating-point.     |

---

## 📚 References
- Burden, R. L., & Faires, J. D. (2011). *Numerical Analysis* (9th ed.). Cengage Learning.  
- IEEE 754 Floating-Point Standard.
