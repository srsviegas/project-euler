/* You are given the following information, but you may prefer to do some research for yourself.
    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)? */

#include <stdio.h>
#include <time.h>

enum week{Mon = 1, Tue, Wed, Thur, Fri, Sat, Sun};
enum month{Jan = 1, Feb, Mar, Apr, May, Jun, Jul,
           Aug, Sep, Oct, Nov, Dec};

typedef struct {
    int day;
    enum month month;
    int year;
    enum week dweek;
} Date;

int is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int days(enum month month, int year) {
    if (month == Feb) {
        if (is_leap_year(year))
            return 29;
        else
            return 28;
    }
    else {
        switch(month) {
            case Sep:
            case Apr:
            case Jun:
            case Nov:
                return 30;
                break;
            default:
                return 31;
        }
    }
}

int date_is_not(int day, enum month month, int year, Date date) {
    return !(date.day == day && date.month == month && date.year == year);
}

void next_date(Date *date) {
    date->day++;
    date->dweek++;
    
    if (date->day > days(date->month, date->year)) {
        date->day = 1;
        date->month++;
        if (date->month > Dec) {
            date->month = Jan;
            date->year++;
        }
    }

    if (date->dweek > Sun)
        date->dweek = Mon;
}

int main() {

    clock_t time = clock();

    Date date = {1, Jan, 1900, Mon};
    int sundays = 0;

    // Move till January 1, 1901
    while(date_is_not(1, Jan, 1901, date)) {
        next_date(&date);   
    }

    // Find all sundays on the first of the month
    while(date_is_not(31, Dec, 2000, date)) {
        next_date(&date);
        if (date.dweek == Sun && date.day == 1)
            sundays++;
    }

    printf("sundays on the first of the month: %d", sundays);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}