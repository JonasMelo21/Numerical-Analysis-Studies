# Exercise 16

![ex16](image.png)

The implementation of Newton's Method for P0 = \(\pi\) can be found [here](ex16a.c).  
Spoiler.: The result is unusual for the method because in the first iteraction we have:

$$
\(p_1\) = \(p0\) - \frac{f(p0)}{f'(p0)}
$$

But 

$$
\(p0\) = 1.57080 
$$

and

$$
 \frac{f(p0)}{f'(p0)} = 1.57080
$$

So 

$$
\(p1\) = 0
$$

and

$$
\frac{f(p1)}{f'(p1)} = 0/0 
$$

That's why Newton Method doesn't work, because of the division by 0 error.



Implementation with [p0 = 5π](ex16b.c)

Implementation with [p0 = 10π](ex16c.c)
