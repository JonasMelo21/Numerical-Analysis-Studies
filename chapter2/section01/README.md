# The Bisection Method

Welcome to Bisection Method's section! In this section there will be exercicses from the [text book used in this repository](https://drive.google.com/file/d/1qTyRvL0rwDiC3Ki8AEHKxQVENtCQenei/view?usp=sharing)
and a [Project](projectSection01/) related to the method studied in this folder. Now, let's dive into a brief explanation of how bisection technique works!

## How Does Bisection Approach Works ?
There are some conditions we need to verify before applying the Bisection Method:
  - There has to be a function f(x) continuous on the interval [a,b].
  - The values of the function for a and b, which are f(a) and f(b) must have opposite signs. Which means: f(a) * f(b) < 0.

If the conditions above are true, then we find a solution for f(x) = 0 through a **Binary Search** following the steps below:
  1. Define a midpoint between a and b, denoted by **p**. So: p = a + (b - a)/2.
  2. If F(p) = 0, then we have found the solution.
  3. If F(p) has the same sign of F(a), then the solution is between p and b. So we search for the solution in the new interval which is [p,b].
  4. If not, the solution is between a and p. So we do another binary-search within the range [a,p]. And the new value of b is p.
  5. We keep doing steps 2 through 4 until we find a number p that satisfies F(p) = 0.

The [exercises](exercises/) from the book are solved in a markdown file or in a programm in C language.
