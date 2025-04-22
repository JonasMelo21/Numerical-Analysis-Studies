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
 * This program implements Newton's Method to find the minimum value of D(x), 
 * as described in the corresponding README file. D(x) represents the distance 
 * between two points in a specific mathematical context.
 *
 * Notes:
 * - The mathematical derivation of D(x) and the problem details 
 *   can be found in the README file.
 * - This implementation is educational and aims to reinforce concepts of 
 *   numerical optimization and root-finding techniques.
 *
 */

#include<math.h>
#include<stdio.h>


double f(double x){
    return 2*x - 4 - (2 /pow(x,3)) + (2 / pow(x,2));
}

double derivative(double x){
    return 2 + (6 / pow(x,4)) - (4/pow(x,3));
}

double newtonMethod(double p0,double tolerance,int maxIteractions){
    double p;
    int i = 1;
    while(i <= maxIteractions){
        p = p0 - (f(p0)) / derivative(p0);
        if(fabs(p - p0) <= tolerance){
            printf("\nNewton Method executed successfully after %d iteractions\n",i);
            return p;
        }
        p0 = p;
        i++;
    }
    return -1;
}

int main(){
    double p0 = 1;
    double tolerance = pow(10,-4);
    int maxIteractions = 30;
    double solution = newtonMethod(p0,tolerance,maxIteractions);
    if(solution == -1){
        printf("Newton Method Failed\n");
    }
    else{
        printf("Value of x which D(x) is minimized by Newton Method: %.4f\n",solution);
    }

    // Output:
    // Newton Method executed successfully after 4 iteractions
    // Value of x which D(x) is minimized by Newton Method: 1.8668
    return 0;
}