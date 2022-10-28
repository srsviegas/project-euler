/* In the United Kingdom the currency is made up of pound (£) and pence (p). 
There are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

It is possible to make £2 in the following way:
    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins? */

#include <stdio.h>
#include <time.h>

int sum(int coins[7]) {
    int values[7] = {1, 2, 5, 10, 20, 50, 100};
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += coins[i]*values[i];
        if (sum > 200)
            return -1;
    }
    return sum;
}

int main() {

    clock_t time = clock();

    int p = 1;

    for (int a = 0; a <= 200; a++) {
        for (int b = 0; b <= 100; b++) {
            for (int c = 0; c <= 40; c++) {
                for (int d = 0; d <= 20; d++) {
                    for (int e = 0; e <= 10; e++) {
                        for (int f = 0; f <= 4; f++) {
                            for (int g = 0; g <= 2; g++) 
                            {
                                int coins[7] = {a, b, c, d, e, f, g};
                                if (sum(coins) == 200)
                                    p++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("permutations: %d", p);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}