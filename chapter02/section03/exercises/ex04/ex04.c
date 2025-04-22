/*
    Created by Jonas H. Melo on 2024/09/29
    This file is protected under MIT license

    This code is part of my studies in numerical analysis,
    following Section 3 of Chapter 2 in the book "Numerical Analysis"
    by Richard L. Burden and J. Douglas Faires, 11th edition.

    Approach: Let's use Newton's, Secant and False Position methods 
    to find p3 for the equation f(x) = -x^3 - cos(x) with
    p0 = -1 and p1 = 0.
*/

#include<stdio.h>
#include<math.h>

// Definindo a função f(x)
double f(double x){
    return -pow(x, 3) - cos(x);
}

int main(){
    double p0 = -1;  // p0 inicial
    double p1 = 0;   // p1 inicial
    double p;        // p será a próxima estimativa da raiz
    int i = 2;       // Contador para iterações


    printf("Secant Method\n");
    // Usando o Método da Secante
    while(i <= 3){
        printf("\tP: %.5f\n", p);
        printf("\tf(p): %.5f\n\n", f(p));
        printf("\tp0: %.5f\n", p0);
        printf("\tf(p0): %.5f\n\n", f(p0));
        printf("\tp1: %.5f\n", p1);
        printf("\tf(p1): %.5f\n\n", f(p1));

        p = p1 - f(p1) * (p1 - p0) / (f(p1) - f(p0));  // Corrigida a fórmula da Secante (parênteses)
        p0 = p1;  // Atualiza p0
        p1 = p;   // Atualiza p1
        i++;
    }
    printf("P3 with Secant Method: %.5lf\n\n----------------------\n\n", p);  // Exibe o resultado do Método da Secante


    // Usando o Método da Falsa Posição
    p0 = -1;  // Redefinindo p0
    p1 = 0;   // Redefinindo p1
    int j = 2;

    printf("False Position Method\n");
    while(j <= 3){
        // Fórmula da Falsa Posição
        p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));

        // Debugging opcional: Print para ajudar na visualização de cada passo
        printf("\tP: %.5f\n", p);
        printf("\tf(p): %.5f\n\n", f(p));
        printf("\tp0: %.5f\n", p0);
        printf("\tf(p0): %.5f\n\n", f(p0));
        printf("\tp1: %.5f\n", p1);
        printf("\tf(p1): %.5f\n\n", f(p1));

        // Verifica onde está a raiz e ajusta p0 ou p1
        if(f(p) * f(p0) < 0){
            p1 = p;  // Atualiza p1 se a raiz estiver entre p e p0
        } else {
            p0 = p;  // Atualiza p0 se a raiz estiver entre p e p1
        }
        j++;
    }

    printf("P3 with False Position Method: %.5f\n", p);  // Exibe o resultado do Método da Falsa Posição

    return 0;
}
