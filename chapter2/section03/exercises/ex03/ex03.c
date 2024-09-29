#include<stdio.h>
#include<math.h>

double f(double x){
    return pow(x, 2) - 6;
}

int main() {
    double p0 = 3;
    double p1 = 2;
    double p;

    // Using Newton's method
    int i = 2;
    while(i <= 3){
        p = p1 - f(p1) / (2 * p1);  // Usei a derivada f'(x) = 2x diretamente
        p0 = p1;
        p1 = p;
        i++;
    }
    printf("P3 with Newton's method: %.5f\n", p);

    // Using Secant Method
    int j = 2;
    while(j <= 3){
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
        p0 = p1;
        p1 = p;
        j++;
    }
    printf("P3 by Secant Method: %.5f\n", p);

    // Using False Position Method (corrigido)
    p0 = 3;
    p1 = 2;
    int k = 2;
    while(k <= 3) {
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));

        // Verificar onde a raiz está e atualizar os limites
        if(f(p) * f(p0) < 0) {
            p1 = p;  // A raiz está entre p0 e p, atualize p1
        } else {
            p0 = p;  // A raiz está entre p1 e p, atualize p0
        }
        k++;
    }
    printf("P3 with False Position Method: %.5f\n", p);

    return 0;
}
