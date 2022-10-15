/* Find the index of the first term in the Fibonacci sequence to contain 1000 digits */

#include <stdio.h>
#include <time.h>

int count_digits(long double n) {
    int i;
    for (i = 0; n > 1; i++) {
        n /= 10;
    }
    return i;
}

int main() {

    clock_t time = clock();

    long double current = 1, last = 0;
    int term = 0;

    while (count_digits(current) < 1000) {
        term++;
        current += last;
        last = current - last;
    }

    printf("term: %d", term+1);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}