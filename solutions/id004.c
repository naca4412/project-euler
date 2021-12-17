/*
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <math.h>
#define N 999

int main() {
    int i = 100, j, p, larg_pal = 1, num_digits, first_d, last_d, flag, temp;

    while(i <= N){
        j = i;

        while(j <= N){
            p =  i*j;
            num_digits = log10(p) + 1;
            temp = p;
            flag = 0;
            
            while(num_digits/2 > 0 && flag == 0){
                first_d = temp/(pow(10, num_digits-1));
                last_d = temp%10;

                if (first_d != last_d)
                    flag = 1;
                else{
                    temp -= first_d*(pow(10, num_digits-1));
                    temp /= 10;
                    num_digits -= 2;
                }
            }

            // The number is palindrome
            if (flag == 0)
                if(p > larg_pal)
                    larg_pal = p;
            j++;
        }
        i++;
    }
    printf("larg_pal = %d", larg_pal);
    return 0;
}