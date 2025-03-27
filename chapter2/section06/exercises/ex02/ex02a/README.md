# Exercise 2A

## Finding Roots with Newton's Method
[This C code yielded the roots bellow(click here to see the code)](ex02a.c)

| Root | Value |
----------------
| x1   |- 4.12311|
----------------
| x2   |+ 4.12311|

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
    \frac{P(x)}{Q(x)} = \frac{x^{4} +5x^{3} - 9x^{2} − 85^{x} -136}{(x + 4.12311)(x - 4.12311)} = 
$$
