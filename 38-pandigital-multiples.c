/* Take the number 192 and multiply it by each of 1, 2, and 3:
    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, 
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the 
concatenated product of an integer with (1,2, ... , n) where n > 1? */

#include <stdio.h>
#include <time.h>
#include <math.h>

int len(int n) {
    int l = 0;
    while (n > 0) {
        n /= 10;
        l++;
    }
    return l;
}

int first(int n) {
    while (n > 9)
        n /= 10;
    return n;
}

int is_pandigital(int n) {
    /* We already know that 918273645 is pandigital,
    so is not necessary to search for anything before that */
    if (first(n) != 9)
        return 0;

    int arr[10] = {1};
    int aux, mod, i;
    int pandigital = 0;
    for (i = 1; pandigital < pow(10, 8); i++) {
        aux = n*i;
        pandigital = pandigital*pow(10, len(aux)) + aux;
        while (aux > 0) {
            mod = aux % 10;
            arr[mod]++;
            aux /= 10;
            if (arr[mod] > 1)
                return 0;
        }
    } return pandigital;
}

int main() {
    
    clock_t time = clock();

    int pandigital;
    int largest = 0;

    for (int i = 9; i < 10000; i++) {
        pandigital = is_pandigital(i);
        if (pandigital > largest)
            largest = pandigital;
    }

    printf("the largest one is: %d", largest);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}