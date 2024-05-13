# Taylor Polynomial for Natural Logarithm Series
## Introduction
The Nth term of the Taylor Polynomial for the Natural Logarithm is:

![Image](image.png)

The value of ln 1.5 to eight decimal places is 0.40546511. 
Let’s construct an algorithm to determine the minimal value of N required for:

![Image1](image1.png)

From calculus we know that if 

![Image2](image2.png)

 is an alternating series with limit A whose terms decrease in magnitude, then A and the Nth partial sum

![Image3](image3.png)

differ by less than the magnitude of the (N + 1)st term; that is,

![Image4](image4.png)

The following algorithm uses this bound for x = 1.5 and tolerance = 0.00001.
[algorithm](naturalLogTaylorSeries.c)
