<p>Let's describe the method with mathematical reasoning.</p>

<p>Given a function \( f(x) \) continuous in the interval \([a,b]\), with a root \( P \) such that \( f(P) = 0 \), there is a point \( P_n \) which is accurate enough to satisfy \( f(P_n) \approx 0 \) with precision \( 10^z \), where \( z \) is the accuracy.</p>

<p>The next point of the iteration is the x-intercept of the tangent line that crosses the current point.</p>

<p>However, the equation of the tangent line is:</p>
$$
f(x) - f(x_0) = f'(x_0) \cdot (x - x_0)
$$
where \( x_0 \) is a known point between \([a,b]\).

<p>The point that belongs both to the line above and the x-axis is the point where \( f(x) = 0 \), so:</p>
$$
f(x) - 0 = f'(x_0) \cdot (x - x_0)
$$

<p>Dividing both sides by \( f'(x_0) \), we get:</p>
$$
\frac{f(x)}{f'(x_0)} = x - x_0
$$

<p>Subtracting \( x_0 \) from both sides:</p>
$$
x = x_0 - \frac{f(x_0)}{f'(x_0)}
$$

<p>So if we have an initial approximation \( P_0 \), the next point \( P_1 \) will be:</p>
$$
P_1 = P_0 - \frac{f(P_0)}{f'(P_0)}
$$