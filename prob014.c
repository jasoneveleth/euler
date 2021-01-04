#include <stdio.h>

long next(long);

long next(long curr) {
    if (curr % 2 == 0) {
        return curr/2;
    } else {
        return 3*curr + 1;
    }
}

int main(void) {
    long counter = 0;
    long curr = 1;
    long max = 0;
    long max_num = 1;

    for (int i = 1; i < 1000000; i++) {
        counter = 0;
        curr = i;

        while (((curr = next(curr)) != 1) && curr > 0) {
            counter++;
        }
        if (counter > max) {
            max = counter;
            max_num = i;
        }
    }
    printf("length = %ld, number = %ld\n", max, max_num);
    return 0;
}
