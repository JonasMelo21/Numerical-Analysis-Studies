# **Zeros of Polynomials and Muller's Method** 

This section explores the **Horner's Method** for efficient polynomial evaluation and the **Müller's Method** for finding roots of functions.  

---

## **Horner's Method**  

Horner's Method is an algorithm used to evaluate polynomials efficiently and perform polynomial division. Given a polynomial:  

$$
P(x) = a_n x^n + a_{n-1} x^{n-1} + \dots + a_1 x + a_0
$$

instead of computing each term separately, Horner's Method rewrites it as:  

$$
P(x) = (...((a_n x + a_{n-1})x + a_{n-2})x + \dots + a_1)x + a_0
$$

This form reduces the number of multiplications and additions required, making it computationally efficient.  

### **Algorithm for Polynomial Evaluation using Horner's Method**  
Given a polynomial $\ P(x) $ of degree $\ n $ and a value $\ x_0 $, Horner's method computes $\ P(x_0) $ as follows:  

1. Set $\ b_n = a_n $ (initialize the coefficient).  
2. For $\ i = n-1 $ down to $\ 0 $, compute:  

   $$
   b_i = b_{i+1} x_0 + a_i
   $$

3. The final value $\ b_0 $ is $\ P(x_0) $.  

This method also allows efficient polynomial division when searching for roots.  

---

## **Müller's Method**  

Müller's Method is a root-finding algorithm that generalizes the **Secant Method** by approximating the function with a quadratic polynomial instead of a linear one.  

Given three points $\ x_0, x_1, x_2 $, the function is approximated by a **parabola** of the form:  

$$
P(x) = a(x - x_2)^2 + b(x - x_2) + c
$$

where:
- $\ a $ represents the curvature,
- $\ b $ is the slope at $\ x_2 $,
- $\ c $ is $\ f(x_2) $.  

### **Algorithm for Müller's Method**  
1. Choose three initial points $\ x_0, x_1, x_2 $.  
2. Compute divided differences:
   - $\ \delta_1 = \frac{f(x_1) - f(x_0)}{x_1 - x_0} $
   - $\ \delta_2 = \frac{f(x_2) - f(x_1)}{x_2 - x_1} $
   - $\ a = \frac{\delta_2 - \delta_1}{x_2 - x_0} $  
3. Compute:
   - $\ b = a(x_2 - x_1) + \delta_2 $  
   - $\ c = f(x_2) $  
4. Solve the quadratic equation:

   $$
   x_3 = x_2 - \frac{2c}{b \pm \sqrt{b^2 - 4ac}}
   $$

   choosing the denominator with the **larger absolute value** to ensure numerical stability.  
5. Replace $\ x_0, x_1, x_2 $ with $\ x_1, x_2, x_3 $ and repeat until convergence.  

Müller’s Method is particularly useful for **complex roots** since it does not require real derivatives.  

---

## **Comparison**
| Method      | Order of Convergence | Key Feature |
|------------|---------------------|-------------|
| Horner's   | $\ O(n) $           | Efficient polynomial evaluation |
| Müller's   | Superlinear ($\ A \approx 1.84 $) | Quadratic interpolation for root finding |

---

## **Exercises Solved**  

Here is the folder containing the solved exercises of this section ---> [exercises](exercises/)
