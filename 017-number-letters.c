/* If the numbers 1 to 5 are written out in words: one, two, three, four, 
five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out
in words, how many letters would be used? */

#include <stdio.h>
#include <time.h>
#include <string.h>

int ctoi(char c) {
    return (int)c - 48;
}

void i_to_numeral(int n, char numerals[][50]) {
    char string[50] = {0};
    char digits[5] = {0};
    sprintf(digits, "%4.0d", n);
    if (n > 99)
        sprintf(string, "%s hundred", numerals[ctoi(digits[1])]);
    if (n % 100 && n > 99)
        sprintf(string, "%s and %s", string, numerals[n % 100]);
    else if (n % 100)
        sprintf(string, "%s %s", numerals[ctoi(digits[2])*10], numerals[ctoi(digits[3])]);

    strcpy(numerals[n], string);
}

int count_letters(char str[50]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '-')
            count++;
    }
    return count;
}

int main() {

    clock_t time = clock();

    char numerals[1001][50] = {"", "one", "two", "three", "four", "five", 
    "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    strcpy(numerals[30], "thirty");
    strcpy(numerals[40], "forty");
    strcpy(numerals[50], "fifty");
    strcpy(numerals[60], "sixty");
    strcpy(numerals[70], "seventy");
    strcpy(numerals[80], "eighty");
    strcpy(numerals[90], "ninety");
    strcpy(numerals[100], "one hundred");
    strcpy(numerals[1000], "one thousand");

    for (int i = 21; i < 1000; i++) {
        if (numerals[i][0] == '\0') {
            i_to_numeral(i, numerals);
        }
        //printf("%s\n", numerals[i]);
    }

    int sum = 0;
    for (int i = 1; i < 1001; i++) {
        sum += count_letters(numerals[i]);
    }

    printf("sum of letters: %d", sum);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}