/* The fraction 49/98 is a curious fraction, as an inexperienced mathematician 
in attempting to simplify it may incorrectly believe that 49/98 = 4/8, 
which is correct, is obtained by cancelling the 9s. 

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, 
less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, 
find the value of the denominator. */

#include <stdio.h>
#include <time.h>

int main() {

    clock_t time = clock();

    int fractions[4][2] = {0};
    int i = 0;
    int num = 1;
    int den = 1;
    int mod;

    for (int b = 11; b < 100; b++) {
        for (int a = 10; a < b; a++) {
            if ((double)a/b == (double)(a/10)/(b%10) && (a%10)==(b/10)) {
                fractions[i][0] = a;
                fractions[i][1] = b;
                printf("%d/%d\n", a, b);
                i++;
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        num *= fractions[j][0];
        den *= fractions[j][1];
    }
    mod = num % den;

    printf("product: %d/%d\n", num, den);
    printf("lowest terms: %d/%d", num/mod, den/mod);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}