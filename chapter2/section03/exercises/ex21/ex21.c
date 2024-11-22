/*
 * Created by: Jonas H. Melo
 * Created on: 2024/11/21
 * License: MIT
 *
 * Description:
 * This file is part of my numerical analysis studies, based on
 * Section 3 of Chapter 2 from the book "Numerical Analysis"
 * by Richard L. Burden and J. Douglas Faires, 11th edition.
 *
 * Objective:
 * We'll use Newton Method to compute the roots for 4x^2 -exp(x) - exp(-x)
 * with the following initial approximations p0 = {0,1,3,5,10}
 * 
 */

#include<math.h>
#include<stdio.h>

double f(double x){
	return pow(x,2)*4 - exp(x) - exp(-x);
}

double derivative(double x){
	return 8*x - exp(x) + exp(-x);
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
		printf("\nNewton Method failed\n");
	}
}

int main(){
	double tol = pow(10,-5);	//Accuracy required
	int maxIteractions = 30;	// Maximum number of iteractions
	double approximations[] = {1,3,5,10};	// initial approximations
	
	// Root with initial approximation = 0
	double solution = newtonMethod(0,tol,maxIteractions);
	if(solution == -1){}
	else{
		printf("Solution for p0 = 0: %.5f\n",solution);
	}
	double p0;
	// Method executed with the pther approximations
		for(int i = 0; i < (sizeof(approximations) / sizeof(approximations[0])); i++){
			p0 = approximations[i];
			solution = newtonMethod(p0,tol,maxIteractions);
			if(solution ==-1){}
			else{
				printf("Root for p0 = %.5f ----> %.5f",p0,solution);
			}

			solution = newtonMethod(-1*p0,tol,solution);
			if(solution ==-1){}
			else{
				printf("Root for p0 = %.5f ----> %.5f",-1*p0,solution);
			}
	}


	return 0;
}
