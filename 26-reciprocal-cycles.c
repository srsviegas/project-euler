/* A unit fraction contains 1 in the numerator. 

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part. 

Study about unit fractions / repeating decimals:
- The number of repeating digits of the decimal expansion is related to the multiplicative order of the denominator
- Multiplicative order is the smaller natural number k, for the fraction 1/n, that satisfies:
    10^k = 1 (mod n)
- To calculate the order we can use the propriety:
    x^k % n = [(x^(k-1) % n)*x] % n */

#include <stdio.h>
#include <math.h>

int multp_order(int n) {
    int order = 0;
    int oldMod = 1;
    int mod = 0;
    while (mod != 1) {
        order++;
        mod = (oldMod * 10) % n;
        //printf("10^%d mod %d = %d\n", order, n, mod);
        if (order > 1000)
            return 0;
        oldMod = mod;
    }
    return order;
}

int main() {

    int order;
    int largest[2] = {0};

    for(int i = 2; i <= 1000; i++) {
        order = multp_order(i);
        //printf("1/%d\t%d\n", i, order);
        if (order > largest[0]) {
            largest[0] = order;
            largest[1] = i;
        }
    }

    printf("1/%d has a repeating decimal part with period %d\n", 
            largest[1], largest[0]);

}