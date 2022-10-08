/* Work out the first ten digits of the sum of
the one-hundred 50-digit numbers. */

#include <stdio.h>

int main() {

    FILE *arq = fopen("13-numbers.txt", "r");
    long double aux, sum = 0;

    for (int i = 0; i < 100; i++) {
        fscanf(arq, "%Lf", &aux);
        while (aux > 99999)
            aux /= 10;
        sum += aux;
    }

    while (sum < 1000000000)
        sum *= 10;

    printf("%.0Lf", sum);
}
