# Solution

As shown in the README file, we need to prove that the limit of the series \( \{X_n\} = \frac{F_{n+1}}{F_n} \), where \( F_n \) is a number of the Fibonacci sequence, is the golden ratio \( \frac{1 + \sqrt{5}}{2} \).

We have:

\[
\lim_{{n \to \infty}} X_n = L = \frac{F_{n+1}}{F_n}
\]

We know that:

\[
F_{n+1} = F_n + F_{n-1}
\]

Therefore:

\[
\lim_{{n \to \infty}} L = \lim_{{n \to \infty}} \frac{F_n + F_{n-1}}{F_n}
\]

Dividing both terms by \( F_n \):

\[
\lim_{{n \to \infty}} L = 1 + \lim_{{n \to \infty}} \frac{F_{n-1}}{F_n}
\]

If the limit \( L \) exists, then:

\[
L = 1 + \frac{1}{L}
\]

Multiplying both sides by \( L \) to eliminate the denominator, we get:

\[
L^2 = L + 1
\]

Rearranging, we have the quadratic equation:

\[
L^2 - L - 1 = 0
\]

Calculating the discriminant:

\[
\Delta = (-1)^2 - 4 \cdot 1 \cdot (-1) = 1 + 4 = 5
\]

Solving the quadratic equation using the quadratic formula:

\[
L = \frac{-(-1) \pm \sqrt{5}}{2 \cdot 1} = \frac{1 \pm \sqrt{5}}{2}
\]

Since \( L \) must be positive, we choose the positive solution:

\[
L = \frac{1 + \sqrt{5}}{2}
\]

We reach the conclusion that:

\[
\lim_{{n \to \infty}} X_n = L = \frac{1 + \sqrt{5}}{2}
\]
