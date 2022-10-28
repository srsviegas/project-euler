/* Using base_exp.txt, a 22K text file containing one thousand lines with a base/exponent
pair on each line, determine which line number has the greatest numerical value. 

We can just compare the log of each number, as:
log(a^b) = a*log(b) */

#include <stdio.h>
#include <time.h>
#include <math.h>

#define SIZE 1000

void compare(int *largest, int base, int exp, int line) {
    double val = exp * log(base);
    if (val > largest[0]) {
        largest[0] = val;
        largest[1] = line;
    }
}

int main() {

    clock_t time = clock();

    FILE *file = fopen("099-base-exp.txt", "r");
    if (!file) {
        printf("ERR: Couldn't open file.");
        return 1;
    }

    int base, exp;
    int largest[2] = {0};

    for(int i = 0; i < SIZE; i++) {
        fscanf(file, "%d,%d", &base, &exp);
        compare(largest, base, exp, i+1);
    }

    printf("line: %d", largest[1]);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}
