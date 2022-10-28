/* Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits. */

#include <stdio.h>
#include <time.h>

#define MAX 999999

int f(int n) {
    return n*n*n*n*n;
}

int fifth_d_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += f(n % 10);
        n /= 10;
    }
    return sum;
}

int main() {

    clock_t time = clock();

    int sum = 0;

    for (int i = 10; i < MAX; i++) {
        if (i == fifth_d_sum(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }

    printf("sum: %d", sum);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}