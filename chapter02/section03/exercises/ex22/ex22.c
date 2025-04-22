/*
 * Created by: Jonas H. Melo
 * Created on: 2024/11/22
 * License: MIT
 *
 * Description:
 * This file is part of my numerical analysis studies, based on
 * Section 3 of Chapter 2 from the book "Numerical Analysis"
 * by Richard L. Burden and J. Douglas Faires, 11th edition.
 *
 * Objective:
 * Let's find out how many iteractions we need,with Newton Method, to find
 * a root for f(x) = cos(x) - x, with p0 = π/4 and accuracy = 10^(-100)
 */

#include<math.h>
#include<stdio.h>

double f(double x){
	return cos(x) - x;
}

double derivative(double x){
	return -sin(x) -1;
}

int main(){
	double accuracy = pow(10,-100);
	double p0 = M_PI / 4;
	double p = p0 - (f(p0)/ derivative(p0));
	int i = 1;
	while(fabs(p - p0) > accuracy){
		p0 = p;
		p = p0 - (f(p0) / derivative(p0));
		i++;
	}
	printf("\n%d iteractions needed to compute root for cos(x) - x with acurracy 10^(-100)\n",i);
}
