/* The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

Find which starting number, under one million, produces the longest chain. */

#include <stdio.h>

int chainList[100000000] = { 0 };

int simpler_collatz(unsigned long n) {
    if (n % 2 == 0)
        return 1 + collatz(n/2);
    else
        return 1 + collatz(3*n+1);
}

int collatz(unsigned long n) {
    /* If n is too big for the array size, returns the result from a simpler
    version of the collatz function */
    if (n >= 100000000)
        return simpler_collatz(n);

    /* Checks if the current Collatz chain size is already in the list.
    If it is, returns the size stored. */
    if (chainList[n] != 0)
        return chainList[n];

    // If n equals 1, the chain is finished, returns 0
    if (n == 1)
        return 0;

    /* Else, proceeds with the calculations
    - If n is even, n/2
    - If n is odd, 3n+1 */
    if (n % 2 == 0)
        chainList[n] = 1 + collatz(n/2);
    else
        chainList[n] = 1 + collatz(3*n+1);
    // Returns 1 + the size of the rest of the chain
    return chainList[n];
}

int main() {

    int chain;
    int largest[2] = {0};

    for (int i = 2; i < 1000000; i++) {
        chain = collatz(i);
        if (chain > largest[0]) {
            largest[0] = chain;
            largest[1] = i;
        }
    }

    printf("chain size: %d\n", largest[0]);
    printf("initial value: %d", largest[1]);

    return 0;
}
