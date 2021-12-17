/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

#include <stdio.h>
#include <math.h>
#define N 10001

int main(){
    int count = 0, n = 2, flag, i;
    while(count < N){
        i = 2;
        flag = 0;
        while(i <= sqrt(n) && flag == 0){
            
            // "i" is a factor for "n"
            if(n%i == 0)
                flag = 1;
            else
                i++;
        }
        if(flag == 0)
            count++;
        n++;
    }
    printf("10 001st prime number = %d", n-1);
    return 0;
}