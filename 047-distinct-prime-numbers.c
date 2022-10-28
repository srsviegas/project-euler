/* The first two consecutive numbers to have two distinct prime factors are:
    14 = 2 × 7
    15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:
    644 = 2² × 7 × 23
    645 = 3 × 5 × 43
    646 = 2 × 17 × 19

Find the first four consecutive integers to have four distinct prime factors each. 
What is the first of these numbers? */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define N 4

int is_prime(int n) {
    if (n%2==0 || n%3==0)
        return 0;
    for (int f = 5; f <= floor(sqrt(n)); f += 6) {
        if (n % f == 0 || n % (f+2) == 0)
            return 0;
    }
    return 1;
}

int n_factors(int n) {
    int i = 2;
    int factors = 0;
    while (n != 1 && factors <= N) {
        if (is_prime(n)) {
            n = 1;
            factors++;
        } else if (n % i == 0) {
            factors++;
            while (n % i == 0)
                n /= i;
        }
        i++;
    }
    return factors;
}

int main() {

    clock_t time = clock();
    
    int i;
    int consecutives = 0;

    for (i = 2; consecutives < N; i++) {
        if (n_factors(i) == N)
            consecutives++;
        else
            consecutives = 0;
    }

    printf("%d", i-N);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}