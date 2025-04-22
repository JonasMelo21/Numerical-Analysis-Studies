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

double secantMethod(double p0, double p1, double tolerance, int maxIteractions){
	double p;
	int i =2;
	while(i <= maxIteractions){
		p = p1 - (f(p1) * (p1 - p0) ) / (f(p1) - f(p0));
		if(fabs(p - p1) < tolerance){
			printf("\nSecant Method executed successfully after %d iteractions\n",i);
			return p;
		}
		p0 = p1;
		p1 = p;
		i++;
	}
	if(i > maxIteractions){
		printf("Secant Method failed\n");
		return -1;
	}
}

double falsePosition(double p0,double p1,double accuracy,int maxIteractions){
	double p;
	int i = 2;
	while(i <= maxIteractions){
		p = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));
		if(fabs(p - p1) < accuracy){
			printf("\nFalse Method Position executed successfully after %d iteractions\n",i);
			return p;
		}
		if(f(p) * f(p1) < 0){
			p0 = p1;
		}
		p1 = p;
		i++;
	}
	if(i > maxIteractions){
		printf("False Position Method Failed\n");
		return -1;
	}
}

int main(){
	double accuracy = pow(10,-5);
	int maxIteractions = 30;

	// Newton Method with the interval [-1,0]
	double p0 = -1/2;
	double solution = newtonMethod(p0,accuracy,maxIteractions);
	if(solution == -1){}
	else{
		printf("Solution with Newton Method: %.5f\n",solution); 
	}

	// Newton Method with the interval [0,1]
	p0 = 1;
	solution = newtonMethod(p0,accuracy,maxIteractions);
	if(solution == -1){}
	else{
		printf("Solution with Newton Method for p0 = 0: %.5f\n",solution);
	}
	

	// Secant Method within [-1,0]
	double a = -1;
	double b = 0;
	double secant1 = secantMethod(a,b,accuracy,maxIteractions);
	if(secant1 == -1){}
	else{
		printf("Secant Method Solution for [%.lf,%.lf]: %.5f\n",a,b,secant1);
	}
	
	// Secant Method within the interval [0,1]
	double c = -1;
	double d = 1;
	double secant2 = secantMethod(c,d,accuracy,maxIteractions);
	if(secant2 == -1){}
	else{
		printf("Secant Method solution for [%.lf,%.lf]: %.5f\n",c,d,secant2);
	}

	//False Position within[-1,0]
	double falseposition1 = falsePosition(a,b,accuracy,maxIteractions);
	if(falseposition1 == -1){}
	else{
		printf("False Position Solution within [%.lf,%.lf]: %.5f\n",a,b,falseposition1);
	}
	
	// False Position within [0,1]
	falseposition1 = falsePosition(0,1,accuracy,maxIteractions);
	if(falseposition1 == -1){}
	else{
		printf("False Position Solution within [0,1]: %.5f",falseposition1);
	}
	
	// Output:
	// Newton Method executed successfully after 3 iteractions
	// Solution with Newton Method: -0.04066

	// Newton Method executed successfully after 4 iteractions
	// Solution with Newton Method for p0 = 0: 0.96240        

	// Secant Method executed successfully after 5 iteractions
	// Secant Method Solution for [-1,0]: -0.04066

	// Secant Method executed successfully after 7 iteractions
	// Secant Method solution for [-1,1]: 0.96240

	// False Method Position executed successfully after 14 iteractions
	// False Position Solution within [-1,0]: -0.04065

	// False Method Position executed successfully after 8 iteractions
	// False Position Solution within [0,1]: 0.96240
	return 0;
}
