#include <stdio.h>
#include <string.h>

int main(void) {
    /* int units; */
    /* units = 3; // one */
    /* units += 3; // two */
    /* units += 5; // three */
    /* units += 4; // four */
    /* units += 4; // five */
    /* units += 3; // six */
    /* units += 5; // seven */
    /* units += 5; // eight */
    /* units += 4; // nine */

    /* int teens; */
    /* teens = 6; // eleven */
    /* teens += 6; // twelve */
    /* teens += 7; // thirteen */
    /* teens += 7; // fourteen */
    /* teens += 7; // fifteen */
    /* teens += 7; // twelve */
    /* teens += 7; // twelve */
    /* teens += 7; // twelve */
    /* teens += 7; // twelve */
    /* teens += 7; // twelve */

    /* int tens; */
    /* tens = 3; // ten */
    /* tens += 5; // twenty */
    /* tens += 5; // thirty */
    /* tens += 5; // forty */
    /* tens += 5; // fifty */
    /* tens += 5; // sixty */
    /* tens += 5; // seventy */
    /* tens += 5; // eighty */
    /* tens += 5; // ninety */


    /* tens += 5; // */ 

    /* int one_hundred = 7; // hundred */
    /* int hundreds = units + 9*one_hundred; */
    /* int ands = 3; //hundred */

    /* int sum = 10*9*units + 10*teens + 10*tens + 100*hundreds + 900*ands - 9*ands; */
    /* printf("%d\n", sum); */
    char *units[] = {
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    char *teens[] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    };
    char *tens[] = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
    };
    char *hundred[] = {
        "",
        "onehundred",
        "twohundred",
        "threehundred",
        "fourhundred",
        "fivehundred",
        "sixhundred",
        "sevenhundred",
        "eighthundred",
        "ninehundred",
    };
    char *and = "and";

    int stop = 1000;
    int units_place;
    int tens_place;
    int hund_place;
    int curr;
    int sum = 0;
    /* char string[100]; */
    for (int i = 1; i <= stop; i++) {
        curr = 0;
        units_place = i % 10;
        tens_place = (i / 10) % 10;
        hund_place = (i / 100) % 10;

        curr += strlen(hundred[hund_place]);
        /* strcpy(string, hundred[hund_place]); */

        if ((i % 100 != 0) && (i > 100)) {
            curr += strlen(and);
            /* strcat(string, and); */
        }

        if (tens_place == 1) {
            curr += strlen(teens[units_place]);
            /* strcat(string, teens[units_place]); */
        } else {
            curr += strlen(tens[tens_place]);
            curr += strlen(units[units_place]);
            /* strcat(string, tens[tens_place]); */
            /* strcat(string, units[units_place]); */
        }

        sum += curr;
    }

    sum += strlen("onethousand");
    printf("%d\n", sum);
}
