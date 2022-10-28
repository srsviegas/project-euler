/* Starting in the top left corner of a 2×2 grid, and only being able
to move to the right and down, there are exactly 6 routes to the bottom right corner.

Find how many such routes are there through a 20×20 grid. 

On the 2x2 grid the number of routes is given by the permutation of a string of 4
characters with 2 R and 2 D. Therefore, on the 20x20 grid it should be the perm.
of 40 characteres with 20 R and 20 D. 

The number of permutations in this case should be 40!/(20!20!). */

#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n-1);
}

int main() {

    int factNumer, factDenom;
    unsigned long long numer, denom;
    unsigned long long result;

    numer = 1;
    denom = 1;
    factNumer = 40;
    factDenom = 20;
    result = 1;

    do {
        numer *= factNumer;
        factNumer--;
        if (result % denom == 0) {
            result /= denom;
            denom = factDenom;
            factDenom--;
        }
        if (numer % denom == 0) {
            result *= numer/denom;
            denom = 1;
            numer = 1;
            denom = factDenom;
            factDenom--;
        }
    } while(factNumer != 20);

    result *= numer/(fact(factDenom)*denom);

    printf("%llu", result);

    return 0;
}