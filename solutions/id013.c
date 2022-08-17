// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers: save in id013.txt

#include <stdio.h>
#include <string.h>
#define DIM_V      50
#define DIM_RES    DIM_V+2
#define DIM_BUFFER DIM_V+2

void main(){
    char buffer[DIM_BUFFER];
    int v[DIM_V];      // Convert buffer string to integer
    int res[DIM_RES];  // Compute result
    int i, res_temp, carry = 0;
    FILE *fp = fopen("id013.txt", "r");

    // Init res array
    for (i = 0; i < DIM_RES; i++){
        res[i] = 0;
    }
    
    while (fgets(buffer, DIM_BUFFER, fp)){

        // Convert char to integer
        for (i = 0; i < DIM_V; i++){
            v[i] = buffer[(DIM_V-1) - i] - 48;
        }
        
        // Sum arrays
        for (i = 0; i < DIM_RES; i++){
            res_temp = (i < DIM_V) ? (res[i] + v[i] + carry) : (res[i] + carry);
            carry = 0;

            if (res_temp > 9){
                carry++;
                res[i] = res_temp%10;
            }
            else{
                res[i] = res_temp;
            }
        }
    }
    fclose(fp);
    printf("Problem 13 Answer: ");
    
    // Print first 10 digits
    for (i = DIM_RES-1; i >= DIM_RES-10; i--){
        printf("%d", res[i]);
    }
    printf("\n");
}