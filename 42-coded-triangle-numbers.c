/* The nth term of the sequence of triangle numbers is given by, t(n) = 1/2n(n+1); 
so the first ten triangle numbers are:
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position 
and adding these values we form a word value. For example, the word value for SKY is 
19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt, a 16K text file containing nearly two-thousand common English words, how many are triangle words? */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void load_words(char words[2000][15]) {
    FILE *file = fopen("42-words.txt", "r");
    if (!file) {
        printf("ERR: Couldn't open file.");
        return;
    }
    for (int i = 0; !feof(file); i++) {
        fscanf(file, "\"%[^\"]\",", words[i]);
        //printf("%s\n", words[i]);
    }
    fclose(file);
}

int is_triangle(char *word, bool *triangles) {
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
        sum += (int)word[i] - 64;
    return triangles[sum];
}

int main() {

    clock_t time = clock();

    int i, count = 0;

    char words[2000][15] = {0};
    load_words(words);

    bool triangles[400] = {0};
    for (i = 0; i <= 27; i++)
        triangles[i*(i+1)/2] = true;

    for (i = 0; words[i][0] != '\0'; i++) {
        if (is_triangle(words[i], triangles))
            count++;
    }

    printf("count: %d", count);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}