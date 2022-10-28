/* Starting with the number 1 and moving to the right in a 
clockwise direction a 5 by 5 spiral is formed as follows:
    21 22 23 24 25
    20  7  8  9 10
    19  6  1  2 11
    18  5  4  3 12
    17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is 101.

Find the sum of the numbers on the diagonals in a 1001 by 1001 spiral 
formed in the same way.

We can see that the sum, in the 5x5 spiral, is:
1 + 3 + 5 + 7 + 9 + 13 + 17 + 21 + 25
Is fair to assume that the increase value is itself
increasing by two each four terms. */

#include <stdio.h>
#include <math.h>

int find_sum(int number, int term, int inc, int size) {
    // Remove comment to see numbers being generated
    //printf("%d ", number);
    if (number > pow(size, 2))
        return 0;
    else if (term % 4 == 0)
        return number + find_sum(number+inc, term+1, inc+2, size);
    else
        return number + find_sum(number+inc, term+1, inc, size);
}

int main() {
    printf("\nsum: %d\n", find_sum(1, 1, 2, 1001));
    return 0;
}