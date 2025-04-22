# Resolution

## For sin(1/n) with n-> infinite

We know that 1/n gets close to 0 when n gets close to infinite, and sin(x) = x when x is close to 0. So the rate of convergence is O(1/n)

## For sin(1/n^2)

Again, 1/n^2 gets close to 0 when n approximates infinite, but it grows faster than 1/n. That's why it converges in a rate of O(1/n^2)

## For (sin(1/n))^2

We know that sin(1/n) is close to 1/n because 1/n gets close to 0 when n -> infinite and sin(1/n) is almost 1/n when 1/n is close to 0. That gives (sin(1/n))^2 -> O(1/n)^2 = O(1/n^2)

## For ln(n + 1) - ln(n) 

We have ln(n + 1) - ln(n) which is, according to logarithm properties: ln((n + 1) / n) = ln(1 + 1/n)

When n -> infinite, 1/n ->0. And ln(1 + x) is approximately x when x -> 0, so ln(1 + 1/n) = 1/n because 1/n gets close to 0 when n increases to infinite