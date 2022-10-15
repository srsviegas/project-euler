/* Using base_exp.txt, a 22K text file containing one thousand lines with a base/exponent
pair on each line, determine which line number has the greatest numerical value. 

We can just compare the log of each number, as:
log(a^b) = a*log(b) */

#include <stdio.h>
#include <time.h>
#include <math.h>

#define SIZE 1000

void load_values(int *base, int *exp) {
    FILE *file = fopen("99-base-exp.txt", "r");
    if (!file)
        printf("ERR: Couldn't open file.");
    else {
        for (int i = 0; i < SIZE; i++) {
            fscanf(file, "%d,%d", &base[i], &exp[i]);
        }
    }
    fclose(file);
}

void compare(int *largest, int base, int exp, int line) {
    double larg = largest[1] * log(largest[0]);
    double val = exp * log(base);
    if (larg >= val)
        return;
    else {
        largest[0] = base;
        largest[1] = exp;
        largest[2] = line;
    }
}

int main() {

    clock_t time = clock();

    int base[SIZE];
    int exp[SIZE];
    int largest[3] = {0};
    int i;

    load_values(base, exp);

    for(i = 0; i < SIZE; i++) {
        compare(largest, base[i], exp[i], i+1);
    }

    printf("largest: %d^%d", largest[0], largest[1]);
    printf("\nline: %d", largest[2]);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}