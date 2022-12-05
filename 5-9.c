#include <stdio.h>


int day_of_year(int, int, int);
void month_day(int, int, int *, int *);


int main() {
    int pmonth;
    int pday;

    printf("%i\n", day_of_year(2016, 3, 15));
    month_day(2016, 75, &pmonth, &pday);
    printf("%i %i\n", pmonth, pday);
}


static char daytab[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int year, int month, int day) {
    int i, leap;

    if (year < 0 || month < 1 || month > 12 || day > 31) {
        day = -1;
        return -1;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    
    char *p = daytab[leap];
    for (i = 1; i < month; i++)
        day +=  *p++;

    if (day < 1 || (leap == 1 && day > 366 || leap == 0 && day > 365)) {
        day = -1;
        return -1;
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 0 || yearday < 1){
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (leap == 1 && yearday > 366 || leap == 0 && yearday > 365) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    char *p = daytab[leap];
    for (i = 1; yearday > *p; i++)
        yearday = yearday - *p++;


    *pmonth = i;
    *pday = yearday;
}