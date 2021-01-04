#include <stdio.h>

void assign_factors(void);
void print_factors(void);

static int cache[31][10];
/* The ith number in this list is the index of the
 * prime for each row of the cache 
 */
static int convert[30] = {
    -1,
    -1,
    0,
    1,
    -1,
    2,
    -1,
    3,
    -1,
    -1,
    -1,
    4,
    -1,
    5,
    -1,
    -1,
    -1,
    6,
    -1,
    7,
    -1,
    -1,
    -1,
    8,
    -1,
    -1,
    -1,
    -1,
    -1,
    9,
};

void assign_factors(void) {
    for (unsigned i = 2; i < 31; i++) {
        unsigned num = i;
        for (unsigned mod = 2; mod*2 <= i; mod++) {
            while (num % mod == 0) {
                num /= mod;
                cache[i][convert[mod]]++;
            }
        }
        if (num != 1) {
            cache[i][convert[num]]++;
        }
        printf("\n");
    }
}

void print_factors(void) {
    printf("2\t3\t5\t7\t11\t13\t17\t19\t23\t29\n");
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d\t", cache[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    
    assign_factors();
}
