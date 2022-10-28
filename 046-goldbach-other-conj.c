/* It was proposed by Christian Goldbach that every odd composite number can 
be written as the sum of a prime and twice a square.
    9 = 7 + 2×1^2
    15 = 7 + 2×2^2
    21 = 3 + 2×3^2
    25 = 7 + 2×3^2
    27 = 19 + 2×2^2
    33 = 31 + 2×1^2
It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square? */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define N 10000

int is_prime(int n) {
    if (n%2==0 || n%3==0)
        return 0;
    for (int f = 5; f <= floor(sqrt(n)); f += 6) {
        if (n % f == 0 || n % (f+2) == 0)
            return 0;
    }
    return 1;
}

int main() {

    clock_t time = clock();

    int i, j;
    int comp[N] = {1};
    int primes[N] = {2, 3};
    int cIndx = 1, pIndx = 2;
    float result;
    bool found;

    for (i = 4; i < N; i++) {
        if (is_prime(i)) {
            primes[pIndx] = i;
            pIndx++;
        } else if (i % 2) {
            comp[cIndx] = i;
            cIndx++;
        }
    }

    for (i = 1; i < N && i < cIndx; i++) {
        found = false;
        for (j = 0; !found && primes[j] < comp[i] && j < pIndx; j++) {
            result = comp[i] - primes[j];
            if ((int)result % 2 == 0) {
                result = sqrt(result/2);
                if (result == (int)result) {
                    found = true;
                }
            }
        }
        if (!found) {
            printf("%d", comp[i]);
            break;
        }
    }

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}