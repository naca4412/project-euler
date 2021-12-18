/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each
of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <stdio.h>
#define N 10000

int main(){
    int v[N], sum = 0, i, j, k;
    for (i = 0; i < N; i++) // Array initialization
        v[i] = 0;
    for (i = 3; i < N; i++){
        if (v[i] == 0){
            j = 1;
            while (j <= i/2){
                if (i%j == 0) v[i] += j; // j is a factor for i
                j++;
            }
            k = v[i];   // If i = 220 then k = v[220] = 284
            if (k != 1 && k < N && v[k] == 0){
                j = 1;
                while (j <= k/2){
                    if (k%j == 0) v[k] += j; // j is a factor for k
                    j++;
                }
                if (v[k] == i) sum += (i + v[i]);
            }
        }
    }
    printf("SUM = %d\n", sum);
    return 0;
}