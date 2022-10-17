/* The number, 197, is called a circular prime because all rotations of the digits: 
197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million? */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX 1000000

void find_primes(bool *primes) {
    // Initializes all values to true
    for (int i = 2; i < MAX; i++)
        primes[i] = true;

    int p = 2, m;
    while (p < MAX) {
        if (primes[p]) {
            for (m = 2*p; m < MAX; m+=p) {
                primes[m] = 0;
            }
        }
        p++;
    }
}

int ten_exp(int n) {
    int t = 1;
    while(n > 0) {
        t *= 10;
        n /= 10;
    }
    return t;
}

int rotate(int number, int exp) {
    int n = number;
    int first;
    first = n*10;
    n = first%exp;
    first = (first-n)/exp;
    n += first;
    return n;
}

int is_circular_prime(int n, bool *primes) {
    int rot = n;
    int exp = ten_exp(n);
    do {
        rot = rotate(rot, exp);
        if (!primes[rot])
            return 0;        
    } while(rot != n);
    return 1;
}

int main() {

    clock_t time = clock();

    int count = 0;
    bool primes[MAX] = {0};
    find_primes(primes);

    for (int i = 2; i < MAX; i++) {
        if (primes[i] && is_circular_prime(i, primes)) {
            //printf("%d\n", i);
            count++;
        }
    }

    printf("count: %d", count);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}