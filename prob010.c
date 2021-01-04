#include <stdio.h>
#include <math.h>


int main(void) {
    int is_prime;
    unsigned long sum = 2;
    for (unsigned p = 3; p < 2000001; p++) {
        is_prime = 1;
        for (unsigned mod = 2; mod <= sqrt(p); mod++) {
            if (p % mod == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            sum += p;
        }
    }
    printf("sum: %ld\n", sum);
}
