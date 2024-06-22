# Solution

## For (sin(h) / h) when h -> 0:
Given that sinh(h) / h converges to 1 when h -> 0 we have to find the rate of convergence O(g(x)) for sin(h)/h such that:

|sin(h)/h - 1| <= g(x)

We know from taylor series that sin(h) ≈ (h - h^3 / 6).

So sin(h) / h = (h - h^3 / 6) * (1/h) = 1 - h^2/6. Therefore...

|1 - (h^2/6) - 1| = |h^2 / 6| <= h^2. 

We showed that |sin(h)/h - 1| <= h^2 that proves that the series converges in a rate of O(h^2)

## For ((1 - cos(h))) / h when h -> 0:

The taylor expansion of cos(h) is 1 - h^2 / 2. So :

cos(h) = 1 - h^2 / 2

1 - cos(h) = 1 - 1 + h^2/2

1 - cos(h) = h^2 / 2

(1 - cos(h)) / h = h / 2.

So the rate of convergence is O(h)

## For (sin(h) - h*cos(h)) / h:

As showed in the previous questions: 

sin(h) / h = 1 - (h^2/6)

cos(h) = 1 - (h^2/2)

So (sin(h) - h*cos(h)) / h = sin(h) - cos(h) which is equal to:

1 - h^2/6 - 1 + h^2/2 = h^2/2 - h^2/6 = 3*h^2/6 - h^2/6 = 2*h^2/6 = h^2/3 <= h^2. 

So the rate of convergence is O(h^2)

## For (1 - exp(h)) / h:

From taylor series, we have:

exp(h) = 1 + h

1 - exp(h) = 1 - 1 + h

1 - exp(h) = h

(1 - exp(h)) / h = 1

So the rate of convergence is O(h)
