/* The series, 11 + 22 + 33 + ... + 10^10 = 10405071317.
Find the last ten digits of the series, 1¹ + 2² + 3³ + ... + 1000^1000. */

#include <stdio.h>
#include <time.h>

#define SIZE 10

void sum(short *a, short *b) {
    short aux, carry = 0;
    for (int i = SIZE-1; i >= 0; i--) {
        aux = a[i]+b[i]+carry;
        a[i] = aux % 10;
        carry = (aux - a[i]) / 10;
    }
}

void product(short *arr, int m) {
    short aux, carry = 0;
    for (int i = SIZE-1; i >= 0; i--) {
        aux = (arr[i]*m)+carry;
        arr[i] = aux % 10;
        carry = (aux - arr[i]) / 10;
    }
}

void power(short *arr, int n) {
    for (int i = 0; i < SIZE; i++)
        arr[i] = 0;
    int i = SIZE-1;
    int aux = n;
    while (aux > 0) {
        arr[i] = aux % 10;
        aux /= 10;
        i--;
    }
    for (i = 1; i < n; i++) {
        product(arr, n);
    }
}

int main() {
    
    clock_t time = clock();

    short number[SIZE] = {0};
    short aux[SIZE] = {0};
    int i;

    for (i = 1; i <= 1000; i++) {
        power(aux, i);
        sum(number, aux);
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d", number[i]);
    }

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}