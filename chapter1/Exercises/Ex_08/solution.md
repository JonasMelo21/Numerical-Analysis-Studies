# Solution

## A) How many Multiplications and Sums to compute $\left(\sum_{j=1}^i a_i b_j) ?

For...
    i = 1 -> j = 1. So that's 1 multiplication and 0 sums.
    i = 2 -> j = 1,2. So that's 2 multiplication and 1 sum.
    i = 3 -> j = 1,2,3. So that's 3 multiplication and 2 sums.
    ...
    i = n -> j 1,2,3,...,n. So that's n multiplications and (n - 1) sums.

That shows that the number of multiplications will be the sum of the first nth natural numbers:
\[
\frac{(n + 1) \cdot n}{2}
\]

And the number of inner sums will be
\[
\left( \sum_{i=1}^n (i - 1) \right) = \frac{n (n-1)}{2} - n
\]

Let m be the number of inner sums, then the outter sum will have (m - 1) sums, with 
$\m = \frac{n (n-1)}{2} - n

## B) How to rewrite the sum to an equivalent but more efficient ?

The inner sum is equal to
a1(b1) + a2(b1 + b2) + a3(b1 + b2 + b3)...an(b1 + b2 +...+ bn)

So an equivalent but more efficiente approach would be
\[
\sum_{i=1}^n a_i \left( \sum_{j=1}^i b_j \right)
\] 