/* 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included. */

#include <stdio.h>
#include <time.h>

#define MAX 100000

int fact_equal_n(int n, int *factorials) {
    int num = n;
    int sum = 0;
    while (n > 0) {
        sum += factorials[n % 10];
        n /= 10;
        if (sum > num)
            return 0;
    }
    return (sum == num);
}

int main() {

    clock_t time = clock();

    int factorials[10] = {1, 1};
    int sum = 0;

    for (int i = 2; i < 10; i++) {
        factorials[i] = i * factorials[i-1];
        //printf("%d! = %d\n", i, factorials[i]);
    }

    for (int n = 10; n < MAX; n++) {
        if (fact_equal_n(n, factorials)) {
            sum += n;
            printf("%d\n", n);
        }
    }

    printf("sum: %d", sum);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}