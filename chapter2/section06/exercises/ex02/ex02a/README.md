# Exercise 2A

## Finding Roots with Newton's Method
[This C code yielded the roots bellow(click here to see the code)](ex02a.c)

Roots: 
    - x1 = -4.12311
    - x2 = 4.12311
## Reducing the Polynomial to Find Complex Roots

Dividing the polynomial 

$$
P(x) =  x^{4} +5x^{3} - 9x^{2} − 85^{x} -136
$$ 

by the polynomial 

$$
    Q(x) = (x - x1)(x - x2) = (x + 4.12311)(x - 4.12311)
$$

We have the polynomial

$$
    \frac{P(x)}{Q(x)} = \frac{x^{4} +5x^{3} - 9x^{2} − 85^{x} -136}{(x + 4.12311)(x - 4.12311)} = x^{2} + 5x + 8
$$

Let's use quadratic formula to find complex solutions

$$
\Delta = b^{2} - 4 \cdot a \cdot c
$$

$$
\Delta = 5^{2} - 4 \cdot 1 \cdot 8
$$

$$
\Delta = 25 - 32
$$

$$
\Delta = -7
$$

$$
\sqrt{\Delta} = \sqrt{-7}
$$

$$
x = \frac{-b \pm \Delta}{2 \cdot a}
$$

$$
x = \frac{-5 \pm \sqrt{7} \cdot i}{2}
$$

So the complex roots are:

$$
x_{1} = \frac{-(5 + \sqrt{7} \cdot i)}{2}
$$

$$
x_{2} = \frac{-5 + \sqrt{7} \cdot i}{2}
$$
