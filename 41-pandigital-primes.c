/* We shall say that an n-digit number is pandigital if it makes use of all 
the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists? */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

/* The sum of the digits of 8 and 9 pandigital numbers are
36 and 45. A number with a sum of digits divisible by 3 is
itself divisible by 3. Therefore, we just need to verify
7-digits numbers or less. */
#define MAX 7654321

int len(int n) {
    int l = 0;
    while (n > 0) {
        n /= 10;
        l++;
    }
    return l;
}

int not_pandigital(int n) {
    int digits[10] = {1};
    int lenght = len(n);
    while (n > 0) {
        if (digits[n % 10]++ > 1 || n % 10 > lenght)
            return 1;
        n /= 10;
    }
    for (int i = 1; i <= lenght; i++) {
        if (digits[i] == 0)
            return 1;
    }
    return 0;
}

int not_prime(int n) {
    if (n%2==0 || n%3==0)
        return 1;
    for (int f = 5; f <= floor(sqrt(n)); f += 6) {
        if (n % f == 0 || n % (f+2) == 0)
            return 1;
    }
    return 0;
}

int main() {

    clock_t time = clock();

    int n = MAX;

    while (not_pandigital(n) || not_prime(n)) {
        n--;
    }

    printf("largest: %d", n);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}