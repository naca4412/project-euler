/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
----------------------

c = 1000 - a - b => c^2 = (1000 - a - b)^2

a^2 + b^2 = (1000 - a^2 - b^2)^2

a   b       a   b       a   b
1   1       2   1 x     3   1 x
1   2       2   2       3   2 x
1   3       2   3       3   3

*/

#include <stdio.h>
#include <stdbool.h>
int main(){
    int a = 1, b, c, count = 500;
    bool flag = false;

    while (a < count && flag == false){
        b = a + 1;
        flag = false;
        while (b < count && flag == false){
            if ((a*a + b*b) == ((1000 - a - b)*(1000 - a - b))) flag = true;
            else b++;
        }
        if (flag == true){
            c = 1000 - a - b;
            printf("abc = %d * %d * %d = %d\n\n", a, b, c, a*b*c);
        }
        else a++;
    }
    return 0;
}