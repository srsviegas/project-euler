/* Find the sum of the digits of the number 2^1000 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 17
#define MAX_EXP 18

void multiply_by_two(unsigned long long number[SIZE]) {
    unsigned long long auxL, auxH, carry = 0;
    int i, exponent;
    for (i = SIZE-1; i >= 0; i--) {
        auxL = number[i]*2 + carry;
        if (auxL >= (unsigned long long)pow(10, 18)) {
            number[i] = auxL - (unsigned long long)pow(10, 18);
            carry = 1;
        }
        else if (auxL > number[i]) {
            number[i] = auxL;
            carry = 0;
        }
        else {
            auxH = number[i];
            exponent = 0;
            while (auxH >= 10) {
                auxH /= 10;
                exponent++;
            }
            auxL = auxH * pow(10, exponent);
            number[i] =  2*(number[i] - auxL) + carry;
            carry = auxH*2;
        }
    }
}

// Converts unsigned long long array to string
int llutos(char *string, unsigned long long number[], int sizeArr) {
    char aux[20];
    for (int i = 0; i < sizeArr; i++) {
        sprintf(aux, "%llu", number[i]);
        strcat(string, aux);
    }
}

// Converts char to integer
int ctoi(char c) {
    return (int)c - 48;
}

int sum_digits(char *string) {
    int sum = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        sum += ctoi(string[i]);
    }
    return sum;
}

int main() {

    char string[SIZE*MAX_EXP];
    string[0] = '\0';
    unsigned long long number[SIZE] = {0};
    number[SIZE-1] = 2;

    for (int j = 1; j < 1000; j++) {
        multiply_by_two(number);
    }

    llutos(string, number, SIZE);
    printf("%s", string);

    printf("\n\nsum: %d", sum_digits(string));

    return 0;
}