/*
 * This file is protected under MIT license
 * Created by Jonas H Melo on 2024/11/20
 *
 * This code aims to comput myh journey in the field of
 * Numerical Analysis. I'm following the book "Numerical Analysis" 
 * by Richard L. Burden
 *
 * Approach.: We'll use Newton Method to compute the soltion for the equation
 * x^2 - 10*cos(x) = 0 for the initial approximations
 * [-25,25,-50,50,-100,100]
 */

#include<math.h>
#include<stdio.h>

// Implementing the function
double f(double x){
	return pow(x,2) -10 * cos(x);
}

// Implementing the derivative of the function (used in the method)
double derivative(double x){
	return 2*x -10 * (-sin(x));
}


double newtonMethod(double p0, double accuracy, int maxIteractions){
	double p;
	int i = 1;
	while(i <= maxIteractions){
		p = p0 - (f(p0)) / (derivative(p0));
		if(fabs(p - p0) < accuracy){
			printf("\nNewton Method executed successfully after %d iteractions\n",i);
			return p;
		}
		p0 = p;
		i++;
	}
	if(i > maxIteractions){
		printf("\nNewton Method Failed\n");
		return -1; // Error value
	}
}

int main(){
	double accuracy = pow(10,-5); // or 0.00001
	int maxIteractions = 50;
	double approximations[] = {-25,25,-50,50,-100,100};
	double solution = 1; // Just for declaring
	for(int i = 0; i < (sizeof(approximations) / sizeof(approximations[0])); i++){
		solution = newtonMethod(approximations[i], accuracy, maxIteractions);
		if(solution == -1){}
		else{
			printf("Newton Method Solution for initial approximation = %.lf ----> %.5f\n",approximations[i],solution);
		}
	}


	return 0;
}
