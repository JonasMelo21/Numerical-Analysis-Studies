# Improving π Approximation Using Series for Arctangent

To improve the approximation of π, we use the identity:

π/4 = arctan(1/2) + arctan(1/3)

Using this identity, we evaluate the series for arctan(1/2) and arctan(1/3):

arctan(x) = ∑ (-1)^(i+1) * (x)^(2i - 1) / (2i - 1)

## For x = 1/2:

arctan(1/2) = ∑ (-1)^(i+1) * (1/2)^(2i-1) / (2i-1)

## For x = 1/3:

arctan(1/3) = ∑ (-1)^(i+1) * (1/3)^(2i-1) / (2i-1)

To ensure the sum approximates π to within 10^-3, the sum of the series for both arctan(1/2) and arctan(1/3) must be accurate enough such that the total error is less than 10^-3 / 4 for each.

We use the alternating series remainder term to find the necessary number of terms N such that the error term is smaller than the desired precision.

### For arctan(1/2):

The error term after summing N terms:

E(N, 1/2) <= | (-1)^(N+1) * (1/2)^(2N+1) / (2N+1) |

### For arctan(1/3):

The error term after summing N terms:

E(N, 1/3) <= | (-1)^(N+1) * (1/3)^(2N+1) / (2N+1) |

To ensure the total error is less than 10^-3, the sum of these errors should be less than 10^-3.

### Estimating N for arctan(1/2):

(1/2)^(2N+1) / (2N+1) < 10^-3 / 2

1 / ((2N+1) * 2^(2N+1)) < 10^-3 / 2

(2N+1) * 2^(2N+1) > 2 * 10^3

Estimating N:

For N = 3:

(2 * 3 + 1) * 2^(2 * 3 + 1) = 7 * 2^7 = 7 * 128 = 896

This is less than 2000, so try N = 4:

(2 * 4 + 1) * 2^(2 * 4 + 1) = 9 * 2^9 = 9 * 512 = 4608

This exceeds 2000, so N = 4 seems sufficient for arctan(1/2).

### Estimating N for arctan(1/3):

(1/3)^(2N+1) / (2N+1) < 10^-3 / 2

1 / ((2N+1) * 3^(2N+1)) < 10^-3 / 2

(2N+1) * 3^(2N+1) > 2 * 10^3

For N = 2:

(2 * 2 + 1) * 3^(2 * 2 + 1) = 5 * 3^5 = 5 * 243 = 1215

This is less than 2000, so try N = 3:

(2 * 3 + 1) * 3^(2 * 3 + 1) = 7 * 3^7 = 7 * 2187 = 15309

This far exceeds 2000, so N = 3 is sufficient for arctan(1/3).

### Conclusion:

Thus, summing up to 4 terms for arctan(1/2) and 3 terms for arctan(1/3) should give a result within 10^-3 accuracy for π.
