# Solution to exercise 16

It's been shown that it's possible to find approximations for how many iteractions are needed to compute the pn value of a function such that pn - p <= 10^(-precision). Where precision = number of digits.

It's also been shown that for 4 digits of precision, there is:

| pn - p | <= 10^(-3)

As pn = 1 + 1/n and p = 1...

| 1 + 1/n - 1 | <= 1 / 1000

1/n <= 1 / 1000

n >= 1000