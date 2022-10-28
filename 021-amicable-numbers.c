/* Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an 
amicable pair and each of a and b are called amicable numbers.

Evaluate the sum of all the amicable numbers under 10000.


The sum of divisors of n is given by the product of
[p^(m+1) -1]/[p - 1], where p is a prime factor of n. */

#include <stdio.h>
#include <math.h>

int results[50000] = {0};

int d(int n) {
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i + n/i;
        }
    }
    return sum;
}

int is_amicable(int n) {
    if (results[n] == 0) {
        int divA = d(n);
        int divB = d(divA);
        if (n != divA && n == divB) {
            results[n] = 1;
            results[divA] = 1;
        }
        else {
            results[n] = -1;
            results[divA] = -1;
        }
    }
    return results[n];
}

int main() {

    int sum = 220;
    int i;

    for (i = sum+1; i < 10000; i++) { 
        if (is_amicable(i) == 1) {
            //printf("%d\n", i);
            sum += i;
        }
    }

    printf("\nsum: %d\n", sum);

}