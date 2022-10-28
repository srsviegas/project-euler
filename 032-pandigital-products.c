/* We shall say that an n-digit number is pandigital if it makes use of all the 
digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, 
multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as 
a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum. */

#include <stdio.h>
#include <time.h>

#define MAX 10000

int size(int n) {
    int s = 0;
    while (n > 0) {
        n /= 10;
        s++;
    }
    return s;
}

int is_pandigital(int t[3]) {
    int digits[10] = {0};
    int mod;
    for (int i = 0; i < 3; i++) {
        while(t[i] > 0) {
            mod = t[i] % 10;
            digits[mod]++;
            if (digits[mod] > 1)
                return 0;
            t[i] /= 10;
        }
    }
    for (int i = 1; i < 10; i++) {
        if (digits[i] == 0)
            return 0;
    }
    return 1;
}

int not_in_list(int p, int *list) {
    for (int i = 0; i < 100; i++) {
        if (list[i] == p)
            return 0;
    }
    return 1;
}

int sum_array(int *arr) {
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {

    clock_t time = clock();

    int p, s;
    int products[100] = {0};
    int index = 0;

    for (int a = 1; a < MAX; a++) {
        for (int b = 1; b < a; b++) {
            p = a*b;
            s = size(a) + size(b) + size(p);
            if (s < 9)
                continue;
            else if (s > 9)
                break;
            else if (is_pandigital((int[]){a, b, p}) && not_in_list(p, products)) {
                //printf("%dx%d = %d\n", a, b, p);
                products[index] = p;
                index++;
            }
        }
    }

    printf("sum: %d", sum_array(products));

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}