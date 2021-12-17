/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/
#include <stdio.h>
#include <math.h>
#define N 600851475143

int main(){
    int i = 2, j, max_prime, flag = 0;

    while (i <= sqrt(N)){
        j = 2;
        flag = 0;

        // i is a factor
        if (N%i == 0){
        
            // check if i is prime
            while (j <= sqrt(i) && flag == 0){
                if (i%j == 0)
                    flag = 1;
                else
                    j++;
            }
            if(flag == 0)
                max_prime = i;
        }
        i++;
    }
    printf("MAX_PRIME = %d", max_prime);
    return 0;
}