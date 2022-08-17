/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>
#define N 1000000

void main(){
    int flag, i, v[N], n_max_count, count, max_count = 1;
    long long int temp_n;
    
    // Init
    for (i = 0; i < N; i++){
        v[i] = 0;
    }

    // Evaluate only upper bound
    for (i = N/2; i < N; i++){
        
        count  = 1;
        flag   = 0;
        temp_n = i;

        while (temp_n != 1 && flag == 0){
            
            //Evaluate only if temp_n < 1000000 to avoid segmentation fault
            if (temp_n < N && v[temp_n] != 0){
                count += v[temp_n];
                flag = 1; // Exit condition
            }

            if (flag == 0){
                temp_n = (temp_n%2 == 0) ? temp_n/2 : 3*temp_n + 1;
                count++;
            }
        }

        if (count > max_count){
            max_count = count;
            n_max_count = i;
        }
    }
    printf("NUM LONGEST CHAIN = %d\n", n_max_count);
    printf("LONGEST CHAIN = %d\n", max_count);
}