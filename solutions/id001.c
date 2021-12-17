/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#define N 1000

int main(){
    int sum = 0, i;

    for (i = 3; i < N; i++){
        if (i%3 == 0 || i%5 == 0){
            sum += i;
        }
    }
    printf("SUM = %d", sum);
    return 0;
}