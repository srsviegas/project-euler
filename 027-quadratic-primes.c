/* Euler discovered the remarkable quadratic formula:
    n² + n + 41
It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39. 

The incredible formula n² - 79n + 1601 was discovered, which produces 80 primes for the consecutive values
0 <= n <= 79.

Considering quadratics of the form:
n² + an + b, where |a| < 1000 and |b| <= 1000

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum
number of primes for consecutive values of n, starting with n = 0; */

#include <stdio.h>
#include <time.h>
#include <math.h>

#define PRIMES_QTY 100000

int primes[PRIMES_QTY] = {1, 1};

// Based on the Sieve of Eratosthenes
void generate_primes(int primes[PRIMES_QTY]) {
    int p, m;
    for (p = 2; p < PRIMES_QTY; p++) {
        while (primes[p] == 1) {
            p++;
            if (p >= PRIMES_QTY)
                return;
        }
        for (m = 2*p; m < PRIMES_QTY; m+=p) {
            primes[m] = 1;
        }
    }
}

int primes_quadr(int a, int b) {
    int n = 0;
    while (primes[(n*n)+(a*n)+b] == 0)
        n++;
    return n;
}

int main() {

    clock_t time = clock();

    int a, b;
    int max[3] = {0};
    int count;

    generate_primes(primes);

    for (a = -999; a < 1000; a++) {
        for (b = -1000; b <= 1000; b++) {
            count = primes_quadr(a, b);
            if (count > max[0]) {
                max[0] = count;
                max[1] = a;
                max[2] = b;
            }
        }
    }

    printf("max count: %d\n", max[0]);
    printf("a = %d, b = %d\n", max[1], max[2]);
    printf("product = %d", max[1]*max[2]);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}