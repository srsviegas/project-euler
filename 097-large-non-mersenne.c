/* The first known prime found to exceed one million digits was discovered in 1999, 
and is a Mersenne prime of the form 2^6972593 - 1; it contains exactly 2,098,960 digits. 
Subsequently other Mersenne primes, of the form 2^p-1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 
2,357,207 digits: 28433 x 2^7830457 + 1.

Find the last ten digits of this prime number. */

#include <stdio.h>
#include <time.h>

#define SIZE 10

void print(int *n) {
    for (int i = 0; i < SIZE; i++)
        printf("%d", n[i]);
    printf("\n");
}

void mult(int *n, int m) {
    int carry = 0;
    for (int i = SIZE-1; i >= 0; i--) {
        n[i] = (n[i] * m) + carry;
        carry = 0;
        if (n[i] > 9) {
            carry = n[i]/10;
            n[i] = n[i] % 10;
        }
    }
}

int main() {

    clock_t time = clock();

    int number[SIZE] = {0, 0, 0, 0, 0, 2, 8, 4, 3, 3};

    /* Optimization:
       2^7830457 
       = 2^(7830456+1)
       = 2^7830456 * 2
       = 2^(24*326269) * 2
       = (2^24)^(7830456/24) * 2 */
    for (int i = 1; i <= 7830456/24; i++) {
        mult(number, 16777216);
    }
    mult(number, 2);
    number[SIZE-1] += 1;

    print(number);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}