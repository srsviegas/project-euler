/* The number 3797 has an interesting property. Being prime itself, 
it is possible to continuously remove digits from left to right, and remain prime at each stage: 
3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes. */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX 1000000

void find_primes(bool *primes) {
    for (int i = 2; i < MAX; i++)
        primes[i] = true;
    int m, p;
    for (p = 2; p < MAX; p++) {
        if (primes[p]) {
            for (m = 2*p; m < MAX; m += p)
                primes[m] = false;
        }
    }
}

int size(int n) {
    int exp = 1;
    while(n > 0) {
        n /= 10;
        exp *= 10;
    }
    return exp;
}

int truncate_r(int n) {
    return n / 10;
}

int truncate_l(int n) {
    return n % (size(n)/10);
}

int is_trunc_prime(int n, bool *primes) {
    int left = n;
    int right = n;
    while (left > 10) {
        left = truncate_l(left);
        right = truncate_r(right);
        if (primes[left] == false || primes[right] == false)
            return 0;
    }
    return 1;
}

int main() {

    clock_t time = clock();

    int sum = 0;
    bool primes[MAX] = {0};
    find_primes(primes);

    for (int i = 11; i < MAX; i+=2) {
        if (primes[i] && is_trunc_prime(i, primes)) {
            //printf("%d\n", i);
            sum += i;
        }
    }

    printf("sum: %d", sum);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}