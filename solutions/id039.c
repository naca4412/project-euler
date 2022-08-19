/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <stdio.h>
#include <math.h>

#define MAX_P 1000

struct PERIMETER{
    int value;
    int count;
};

void main(){
    int perimeters[MAX_P] = {0};
    struct PERIMETER p_record = {0, 0};

    for (int a = 1; a <= 400; a++){
        for (int b = a; b <= 400; b++){
            int c = sqrt(a*a + b*b);
            
            // c is a perfect square root
            if (c*c == a*a + b*b){
                int p = a + b + c;

                if (p <= MAX_P){
                    perimeters[p]++;
                    
                    if (perimeters[p] > p_record.count){
                        p_record.value = p;
                        p_record.count = perimeters[p];
                    }
                }
            }
        }
    }
    printf("Problem 39 Answer: %d\n", p_record.value);
}