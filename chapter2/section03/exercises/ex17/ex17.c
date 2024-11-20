/*
 * Author: Jonas H Melo
 * Date: 2024/11/11 (YYYY/MM/DD)
 * License: MIT License
 *
 * Description:
 * This file is part of my studies in Numerical Analysis, 
 * specifically focusing on Section 3 of Chapter 2 from the book:
 * "Numerical Analysis" by Richard L. Burden and J. Douglas Faires (11th edition).
 *
 * Objective:
 * Let's use all the methods learned in this section (Newton, Secant and False Position) to find the solution for the equation f (x) = 230(X^4) + 18(X^3) + 9(X^2) − 221X − 9 = 0.
 * 
 */

#include<math.h>
#include<stdio.h>

double f(double x){
	return 230*pow(x,4) + 18*pow(x,3) + 9*pow(x,2) - 221*x - 9;
}

double derivative(double x){
	return 920*pow(x,3) + 54*pow(x,2) + 18*x - 221;
}

double newtonMethod(double p0, double tolerance, int maxIteractions){
	double p;
	int i =1;
	while(i <= maxIteractions){
		p = p0 - (f(p0)) / (derivative(p0));
		if(fabs(p - p0) < tolerance){
			printf("\nNewton Method executed successfully after %d iteractions\n",i);
			return p;
		}
		p0 = p;
		i++;
	}
	if(i > maxIteractions){
		printf("Newton method failed\n");
		return -1;
	}
}


int main(){
	double accuracy = pow(10,-5);
	int maxIteractions = 30;
	double p0 = -1;
	double solution = newtonMethod(p0,accuracy,maxIteractions);
	if(solution == -1){}
	else{
		printf("Solution with Newton Method: %.5f\n",solution); 
	}
}
