#include <math.h>
#include <stdio.h>

// Derivada de D(x)^2
double derivative(double x) {
    return 2 * x - 4 - (2 / pow(x, 3)) + (2 / pow(x, 2));
}

// Segunda derivada de D(x)^2
double secondDerivative(double x) {
    return 2 + (6 / pow(x, 4)) - (4 / pow(x, 3));
}

// Método de Newton
double newtonMethod(double p0, double tolerance, int maxIterations) {
    double p;
    int i = 1;

    while (i <= maxIterations) {
        double d = derivative(p0);
        double dd = secondDerivative(p0);

        if (fabs(dd) < 1e-10) {  // Evitar divisão por zero
            printf("Second derivative is too small. No solution found.\n");
            return NAN;
        }

        // Atualização de Newton
        p = p0 - d / dd;

        // Verificar convergência
        if (fabs(p - p0) < tolerance) {
            printf("\nNewton Method executed successfully after %d iterations.\n", i);
            return p;
        }

        p0 = p;
        i++;
    }

    // Método falhou em convergir
    printf("Newton Method failed to converge after %d iterations.\n", maxIterations);
    return NAN;
}

int main() {
    double p0 = 2.0;                    // Chute inicial
    double tolerance = pow(10, -4);     // Tolerância
    int maxIterations = 30;            // Máximo de iterações

    double solution = newtonMethod(p0, tolerance, maxIterations);

    if (isnan(solution)) {
        printf("Newton Method Failed.\n");
    } else {
        printf("Value of x that minimizes the distance: %.4f\n", solution);
    }

    return 0;
}
