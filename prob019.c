#include <stdio.h>

// # define MON 0
# define TUE 1
// # define WED 2
// # define THU 3
// # define FRI 4
// # define SAT 5
# define SUN 6

void check(int);

static int sundays = 0;

void check(int days) {
    sundays += ((days + 1) % 7 == SUN);
}

int main() {
    int days = TUE;
    for (int year = 1901; year <= 2000; year++) {
        days += 31; // jan
        check(days);

        days += 28; // feb
        if ((!(year % 400)) || ((!(year % 4)) && (year % 100))) {
            printf("%d leap year!\n", year);
            days += 1;
        }
        check(days);

        days += 31; // mar
        check(days);

        days += 30; // apr
        check(days);

        days += 31; // may
        check(days);

        days += 30; // jun
        check(days);

        days += 31; // jul
        check(days);

        days += 31; // aug
        check(days);

        days += 30; // sep
        check(days);

        days += 31; // oct
        check(days);

        days += 30; // nov
        check(days);

        days += 31; // dec
        check(days);

        days %= 7;
    }
    printf("\nsundays: %d\n", sundays);
}
