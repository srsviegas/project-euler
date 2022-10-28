/* Pythagorean triplet: a < b < c for which a² + b² = c²
Find the product of the pythagorean triplet for which a + b + c = 1000

Study about pythagorean triplets:
1. if (a, b, c) is an p.t., then so is (ka, kb, kc) for any int k
2. Formula for generating triplets:
    m > n > 0
    a = k(m² - n²)
    b = k(2mn)
    c = k(m² + n²) 
    
Sum: k(m² - n²) + k(2mn) + k(m² + n²) = 1000
     k(m² - n² + 2mn + m² + n²) = 1000
     2k(m² + mn) = 1000

Conclusion:     
We only need to check if 1000 is divisible by 2(m² + mn), then calculate 
for which value k, k(a+b+c) = 1000 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sum_triplet(int m, int n) {
    return 2*(pow(m, 2) + (m*n));
}

int* calculate_triplet(int m, int n) {
    static int triplet[3];
    int mSqr, nSqr;

    mSqr = pow(m, 2);
    nSqr = pow(n, 2);

    triplet[0] = mSqr - nSqr; // a
    triplet[1] = 2 * m * n;   // b
    triplet[2] = mSqr + nSqr; // c

    return triplet;
}

void print_triplet(int t[3], int k) {
    for(int i = 0; i < 3; i++)
        printf("%d ", t[i]*k);
}

int prod_triplet(int *t, int k) {
    return t[0]*t[1]*t[2]*k*k*k;
}

int main() {

    int *triplet;
    int m, n, k = 1;
    int sum;
    bool stop = false;

    for (m = 2; m < 1000 && !stop; m++) {
        for (n = 1; n < m && !stop; n++) {
            sum = sum_triplet(m, n);
            if (1000 % sum == 0) {
                triplet = calculate_triplet(m, n);
                stop = true;
            }
        }
    }

    while (sum*k != 1000)
        k++;


    printf("m = %d\nn = %d\n\n", m-1, n-1);

    printf("triplet:\n");
    print_triplet(triplet, 1);
    printf("\nsum = %d", sum);
    printf("\nk = %d", k);

    printf("\n\nfinal triplet:\n");
    print_triplet(triplet, k);

    printf("\n\nproduct = %d\n", prod_triplet(triplet, k));

    return 0;
}
