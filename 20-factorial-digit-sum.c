/* Find the sum of the digits in the number 100! */

#include <stdio.h>
#include <time.h>

#define DIGITS 200

void print_arr(int *arr) {
    int i;
    for (i = 0; arr[i] == 0; i++);
    while (i < DIGITS) {
        if (arr[i] == 0)
            printf("0");
        else
            printf("%1.d", arr[i]);
        i++;
    }
}

void multiply(int *arr, int n) {
    int i, carry = 0;
    for (i = DIGITS-1; i >= 0; i--) {
        arr[i] *= n;
        arr[i] += carry;
        carry = 0;
        if (arr[i] > 9) {
            carry = arr[i];
            carry /= 10;
            arr[i] -= carry*10;
        }
    }
}

int digit_sum(int *arr) {
    int sum = 0;
    for (int i = 0; i < DIGITS; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {

    clock_t time = clock();

    int number[DIGITS] = {0};
    number[DIGITS-1] = 1;

    multiply(number, 100);

    for (int n = 99; n > 1; n--) {
        multiply(number, n);
    }

    print_arr(number);
    printf("\ndigit sum: %d", digit_sum(number));

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;   
}