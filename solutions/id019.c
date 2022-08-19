/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>
#define MONTHS 12

void main(){
    int days[MONTHS] = {
                        31, //JAN
                        28, //FEB
                        31, //MAR
                        30, //APR
                        31, //MAY
                        30, //JUNE
                        31, //JULY
                        31, //AUG
                        30, //SEP
                        31, //OCT
                        30, //NOV
                        31  //DEC
                       };
    int day_month_sunday = 7; // 7 Jan 1900 was a Sunday 
    int num_sundays = 0, num_sundays_1900 = 0, month, year;

    for (year = 1900; year <= 2000; year++){
        
        // Update February
        if (year%4 == 0){
            if (year%100 == 0){
                if (year%400 == 0){
                    days[1] = 29;
                }
                else{
                    days[1] = 28;
                }
            }
            else{
                days[1] = 29;
            }
        }
        else{
            days[1] = 28;
        }
        
        for (month = 0; month < MONTHS; month++){
            
            // Count Sundays that fell on the first of the month
            if (day_month_sunday == 1){
                num_sundays++;

                if (year == 1900){
                    num_sundays_1900++;
                }
            }
            
            // Compute first Sunday of the next month
            while (day_month_sunday < days[month]){
                day_month_sunday += 7;
            }
            day_month_sunday = (month == MONTHS-1) ? (day_month_sunday-days[0]) : (day_month_sunday-days[month]);
        }
    }

    printf("Problem 19 Answer: %d\n", num_sundays-num_sundays_1900);
}