/* The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.) */

#include <stdio.h>
#include <time.h>

#define SIZE_B 19
#define MAX 1000000

int dec_to_bin(int n, int *nbin) {
    int i = SIZE_B-1;
    while (n > 0) {
        nbin[i] = n % 2;
        n /= 2;
        i--;
    }
    
    return i+1;
}

int is_palindr_dec(int n) {
    int digits[6] = {0};
    int i = 0;
    while(n > 0) {
        digits[i] = n % 10;
        n /= 10;
        i++;
    }
    i--;
    for (int j = 0; j < i; j++) {
        if (digits[i] != digits[j])
            return 0;
        i--;
    }
    return 1;
}

int is_palindr_bin(int n) {
    int digits[SIZE_B] = {0};
    int i = dec_to_bin(n, digits);
    while (digits[i] == 0)
        i++;
    for (int j = SIZE_B-1; j > i; j--) {
        if (digits[i] != digits[j])
            return 0;
        i++;
    }
    return 1;
}

int main() {

    clock_t time = clock();

    int sum = 0;

    for(int i = 1; i < MAX; i++) {
        if (is_palindr_dec(i) && is_palindr_bin(i)) {
            //printf("%d\n", i);      
            sum += i;
        }
    }

    printf("sum: %d", sum);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}