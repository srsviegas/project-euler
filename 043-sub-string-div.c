/* The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of 
the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
    d(2)d(3)d(4)  = 406 is divisible by 2
    d(3)d(4)d(5)  = 063 is divisible by 3
    d(4)d(5)d(6)  = 635 is divisible by 5
    d(5)d(6)d(7)  = 357 is divisible by 7
    d(6)d(7)d(8)  = 572 is divisible by 11
    d(7)d(8)d(9)  = 728 is divisible by 13
    d(8)d(9)d(10) = 289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property. */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int primes[7] = {2, 3, 5, 7, 11, 13, 17};

void swap(char *n, int a, int b) {
    char aux = n[a];
    n[a] = n[b];
    n[b] = aux;
}

int ctoi(char n) {
    return n - 48;
}

int is_multiple(char *n) {
    if (ctoi(n[3]) % 2)
        return 0;
    if ((n[2]+n[3]+n[4]-(48*3)) % 3)
        return 0;
    if (n[5] != '5' && n[5] != '0')
        return 0;

    for (int i = 3; i < 7; i++) {
        if ((ctoi(n[i+1])*100 + ctoi(n[i+2])*10 + ctoi(n[i+3])) % primes[i])
            return 0;
    }
    
    return 1;
}

void permute(char *n, int i, unsigned long long *sum) {
    if (i == SIZE-1) {
        if (is_multiple(n))
            (*sum) += atoll(n);
    }
    else 
    {
        for (int j = i; j < SIZE; j++) {
            swap(n, i, j);
            permute(n, i+1, sum);
            swap(n, i, j);
        }
    }
}

int main() {

    clock_t time = clock();

    unsigned long long sum = 0;

    char n[] = "0123456789";
    permute(n, 0, &sum);

    printf("sum: %llu", sum);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}