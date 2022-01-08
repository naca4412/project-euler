/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/

#include <stdio.h>
#include <stdbool.h>
#define N 1000

int main(){
    int v[N], i, count, sum = 0, num2 = 2;
    bool carryOver;

    // Array initialization
    for(i = 0; i < N; i++)
        v[i] = 0;
    v[0] = 2;

    // Compute the number
    for(count = 1; count < N; count++){
        i = 0;
        carryOver = false;
        while(i < N){
            v[i] *= num2;
            if(carryOver) v[i] += 1;
            if(v[i] > 9){
                v[i] -= 10;
                carryOver = true;
            }
            else carryOver = false;
            i++;
        }
    }

    // Sum the digits
    for(i = 0; i < N; i++)
        sum += v[i];

    printf("sum = %d\n\n", sum);
    return 0;
}