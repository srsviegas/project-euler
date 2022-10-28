/* Find the maximum total from top to bottom of the triangle. */

#include <stdio.h>

#define SIZE 15

// Array containing all values from the triangle
int triangle[SIZE][SIZE] = {0};

// Reads triangle from the file "18-triangle.txt"
void read_triangle() {
    FILE *file = fopen("018-triangle.txt", "r");
    if (!file) {
        printf("ERR: Couldn't open file.");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(file, "%d", &triangle[i][j]);
            printf("%2.d ", triangle[i][j]);
        }
        printf("\n");
    }
    fclose(file);
}

int find_sum(int l, int c) {
    if (l >= SIZE)
        return 0;
    else {
        int resultA = find_sum(l+1, c);
        int resultB = find_sum(l+1, c+1);
        if (resultB > resultA) {
            resultA = resultB;
        }
        return triangle[l][c] + resultA;
    }
}

int main() {

    read_triangle();

    printf("\nsum: %d", find_sum(0, 0));

    return 0;
}