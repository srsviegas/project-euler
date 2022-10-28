/* A perfect number is a number for which the sum of 
its proper divisors is exactly equal to the number. 
d(28) = 1 + 2 + 4 + 7 + 14 = 28

A number n is called deficient if the sum of its proper 
divisors is less than n and it is called abundant if this sum exceeds n. */

#include <stdio.h>
#include <stdbool.h>

#define MAX 20161

int abundants[MAX] = {0};
bool isSum[10000000] = {0};
int sumIndex = 0;

int d(int n) {
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n/i)
                sum += n/i;
        }
    }
    return sum;
}

void find_abundants() {
    int i = 0;
    for(int n = 12; n < MAX; n++) {
        if (d(n) > n) {
            abundants[i] = n;
            i++;
            // Remove comment to see all abundant numbers
            //printf("%d\n", n);
        }
    }
}

void find_sums() {
    int i = 0, j;
    while (abundants[i] != 0) {
        for (j = 0; j <= i; j++) {
            //printf("%d + %d = %d\n", abundants[i], abundants[j], abundants[i]+abundants[j]);
            isSum[abundants[i]+abundants[j]] = true;
        }
        i++;
    }
}

int main() {

    unsigned long long sum = 0;

    find_abundants();
    find_sums();

    for (int n = 1; n <= MAX; n++) {
        //printf("%d\t%d\n", n, sums[n]);
        if (!isSum[n])
            sum += n;
    }

    printf("sum = %llu", sum);

    return 0;
}