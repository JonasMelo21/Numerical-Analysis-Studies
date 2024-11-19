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
 * We'll use Newton Method to find Solution for 0 = 1/2 + 1/4 * x^2 - x*sin(x) - 1/2*cos(2*x)
 * 
 * - This implementation is educational and aims to reinforce concepts of 
 *   numerical optimization and root-finding techniques.
 *
 */

#include<math.h>
#include<stdio.h>

double f(double x){
	return 1/2 + 1/4*pow(x,2) - x*sin(x) - 1/2*cos(2*x); 
}

double derivative(double x){
	return 1/2*x -sin(x) - x*cos(x) + sin(2*x);
}

double newtonMethod(double p0,double tol,int maxIteractions){
	double p;
	int i = 1;
	while(i <= maxIteractions){
		p = p0 - (f(p0)) / (derivative(p0));	
		printf("P: %.5f\n",p);
		printf("P0: %.5f\n",p0);
		printf("F(P0): %.5f\n",f(p0));
		printf("F'(P0): %.5f\n",derivative(p0));			
		if(fabs(p - p0) < tol){
			printf("\nNewton Method executed successfully after %d iteractions\n",i);
			return p;
		}
		p0 = p;
		i++;
	}

	if(i > maxIteractions){
		printf("\nNewton Method failed\nRoot found so far: %.5f\n",p);
		return -1;
	}
}

int main(){
	double tolerance = pow(10,-5);
	int max = 30;
	double p0 = M_PI / 2;
	double solution1 = newtonMethod(p0,tolerance,max);
	if(solution1 == -1){}
	else{
		printf("Solution for 0 = 1/2 + 1/4 * x^2 - x*sin(x) - 1/2*cos(2*x): %.5f",solution1); 
	}
	p0 = 5*M_PI;
	double solution2 = newtonMethod(p0,tolerance,max);
	if(solution2 == -1){}
	else{
		printf("Solution for 1/2 + 1/4*x^2 - x*sin(x) - 1/2*cos(2x): %.5f",solution2);
	}

	return 0;
}
