#include <stdio.h>
#include <math.h>
#define N 100

int main(){
    int sum1 = 0, sum2 = 0, i;
    sum1 = pow(N*(N+1)/2, 2);

    for(i = 0; i <= N; i++){
        sum2 += pow(i, 2);
    }
    printf("SUM1 - SUM2 = %d - %d = %d", sum1, sum2, sum1-sum2);
    return 0;
}