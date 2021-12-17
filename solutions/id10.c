/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <math.h>
#define N 200000

int main(){
    int i = 2, j, flag;
    long sum = 0;
    while(i <= N){
        j = 2;
        flag = 0;
        while(j <= sqrt(i) && flag == 0){
            if(i%j == 0)
                flag = 1;
            else
                j++;
        }
        if(flag == 0)
            sum += i;
        i++;
    }
    printf("SUM = %d", sum);
    return 0;
}