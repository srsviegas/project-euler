/* Starting with 1 and spiralling anticlockwise in the following way, a square spiral with
side length 7 is formed.

    37 36 35 34 33 32 31
    38 17 16 15 14 13 30
    39 18  5  4  3 12 29
    40 19  6  1  2 11 28
    41 20  7  8  9 10 27
    42 21 22 23 24 25 26
    43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but
what is more interesting is that 8 out of the 13 numbers lying along both diagonals are
prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side
length 9 will be formed. If this process is continued, what is the side length of the
square spiral for which the ratio of primes along both diagonals first falls below 10%? */

#include <stdio.h>
#include <time.h>
#include <math.h>

int is_prime(int n) {
    if (n == 2 || n == 3)
        return 1;
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

    int primes = 0, total = 1;
    int current = 1;
    int increase = 0;
    int i;

    do {
        increase += 2;
        for (i = 0; i < 4; i++) {
            current += increase;
            if (i != 3 && is_prime(current))
                primes++;
        }
        total += 4;
    } while ((float)primes / total > 0.1);

    printf("side lenght: %d", increase + 1);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}