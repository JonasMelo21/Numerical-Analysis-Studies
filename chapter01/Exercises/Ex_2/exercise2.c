/*  Created by Jonas H. Melo on 05/10/2024
 * The following code is lincensed under MIT license
 *
 * Book: "Numerical Analysis" 9th Edition
   Authors: Richard L. Burden and J. Douglas Faires

   The code bellow aims to compute the value of
   Euler's Number(abbreviated as EN)
   by calculating it in 4 distinct ways:
   EN = 1 / i!                     with 0 <= i <= 5 and  ! is factorial operation
   EN = 1 / i!                     with 0 <= i <= 10 and ! is factorial operation
   EN = 1 / (10 - i)!              with 0 <= i <= 10 and ! is factorial operation
   EN = 1 / (5 - i)!               with 0 <= i <= 5 and  ! is factorial operation


*/

# include<stdio.h>

// Function that returns the factorial of a number 'num'
int factorial(int num){

    // There are no factorial for negative numbers
    if(num < 0){
        return -1;
    }
    // The factorial of 0 is 1
    else if(num ==0){
        return 1;
    }

    int fat = 1;
    // The variable fat is multiplied by 1,2,3,4,...,num in each iteraction,
    // so it will store the value of the factorial and the end of the loop
    for(int i = 1;i <= num;i++){
        fat = fat * i;
    }
    return fat;
}

// Function to calculate the EN(Euler Number) as a series of 1 / i!
double eulerNumber(int n){
    if(n < 0){
        return -1;
    }

    // The variable sum stroes the final result
    double sum = 0;

    // The loop will add to sum the value 1/i! for 0<= i <= n
    for(int j = 0; j <= n; j++){
        sum += 1.0 / (factorial(j));
    }
    return sum;
}

// Function to measure the EN(Euler Number) in terms of 1 / (factor - i)!
double eulerNumberB(int n, int factor){
    // There are n terms in the series, but a series has at least 1 term
    if(n <= 0){
        return -1;
    }
    // The variable sum will store the final result
    double sum = 0;

    // The loop will increment the sum value for each 0 <= i <= n
    for(int i = 0;i < n;i++){
        sum += 1.0 / factorial(factor - i);
    }
    return sum;
}

int main(){
    printf("\nEuler's Number --> 1/(5-i)! --> for n = 5: %.3lf\n",eulerNumberB(5,5));
    printf("\nEuler's Number --> 1 / (10 - i)! --> for n = 10: %.3lf\n",eulerNumberB(10,10));
    printf("\nEuler's Number-->1/(i)!--> for n = 5: %.3lf\n",eulerNumber(5));
    printf("\nEuler's Number--> 1/(i)! --> for n = 10: %.3lf\n",eulerNumber(10));

    printf("\nAs the actual value of 'e' is 2.71828..., the last printed solution is the most accurate");
    return 0;
}
