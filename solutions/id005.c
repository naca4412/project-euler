/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
-------------------------

We must find lcm(1, 2, 3, .., 20)
Quick formula to compute lcm of two numbers is: lcm(a, b) = a*b/gcd(a, b)

Example 1:
a = 25, b = 40
gcd(a, b) = gcd(25, 40) = 5
lcm(a, b) = lcm(25, 40) = 25*40/5 = 200

Example 2:
a = 8, b = 40, c = 60, d = 4
gcd(a, b, c, d) = gcd(8, 40, 60, 4) = 2^2 = 4
lcm(a, b, c, d) = lcm(8, 40, 60, 4) = 2^3 * 3* 5 = 120

a =  8 = 2^3
b = 40 = 2^3 * 5
c = 60 = 2^2 * 3 * 5
d =  4 = 2^2
*/

#include <stdio.h>
#define N 20

// Function declaration
int computeGCD(int a, int b);

int main(){
    int i, lcm_prev, lcm = 1;
    for(i = 2; i <= N; i++){
        lcm_prev = lcm;
        lcm = (lcm_prev/computeGCD(lcm_prev, i))*i;
    }
    printf("lcm(1, ..., %d) = %d\n\n", N, lcm);
    return 0;
}

// Function definition
int computeGCD(int a, int b){
    int temp;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while(a%b != 0){
        temp = a%b; // remainder
        a = b;
        b = temp;
    }
    return b;
}