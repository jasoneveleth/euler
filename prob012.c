#include <stdio.h>
#include <math.h>

int main(void) {
    int n = 4;
    int num_div = 0;
    long tri = 0;
    double squareroot = 0;
    while (n < pow(2, 31)) {
        num_div = 0;
        tri = n*(n+1)/2;
        for (int i = 1; i < sqrt(tri); i++) {
            if (tri % i == 0) {
                num_div++;
            }
        }
        num_div *= 2;
        squareroot = sqrt(tri);
        if ((long)squareroot - squareroot < 1e-307) {
            num_div++;
        }
        if (num_div > 500) {
            break;
        }

        n++;
    }
    printf("tri: %ld, n: %d, divisors: %d\n", tri, n, num_div);
}
