/* Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
    Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
    Pentagonal	 	Pn=n(3n−1)/2	1, 5, 12, 22, 35, ...
    Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal. */

#include <stdio.h>
#include <time.h>

#define START 143
#define MAX 2000000000

unsigned int triang(unsigned int n) {
    return n*(n+1)/2;
}

unsigned int pentag(unsigned int n) {
    return n*(3*n-1)/2;
}

int is_x(unsigned int (*f)(unsigned int), unsigned int n, int start) {
    unsigned int m = start;
    while(n > (*f)(m))
        m += 1000;
    while(n < (*f)(m)) 
        m -= 100;
    while(n > (*f)(m)) {
        m++;
    } return (n == (*f)(m));
}

int main() {

    clock_t time = clock();

    unsigned int h;

    for (unsigned int i = START+1; i < MAX; i++) {
        h = i*(2*i-1);
        if (is_x(pentag, h, i) && is_x(triang, h, i)) {
            printf("%llu\n", h);
            break;
        }
    }

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}