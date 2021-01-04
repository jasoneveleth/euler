#include <stdio.h>

int main(void) {
    int i, j, k;
    int sum = 1000;
    for (i = (sum/3); i < sum; i++) {
        for (j = 1; (j < i) && (i + j <= sum); j++) {
            k = sum - i - j;
            /* printf("%d, %d, %d\n", i, j, k); */
            if ((j*j) + (k*k) == (i*i)) {
                printf("%d, %d, %d\nproduct: %d\n", i, j, k, i*j*k);
            }
        }
    }
}
