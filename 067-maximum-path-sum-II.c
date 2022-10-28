/* Find the maximum total from top to bottom of the triangle. 
    More lines than problem 18 */

#include <stdio.h>
#include <time.h>

#define SIZE 100

void read_triangle(int triangle[][SIZE]) {
    FILE *file = fopen("067-triangle.txt", "r");
    if (!file) {
        printf("ERR: Couldn't open file.");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(file, "%d", &triangle[i][j]);
        }
    }
    fclose(file);
}

int max(int t[][SIZE], int l, int c) {
    return (t[l][c] > t[l][c+1] ? t[l][c] : t[l][c+1]);
}

int main() {

    clock_t time = clock();

    int triangle[SIZE][SIZE] = {0};
    read_triangle(triangle);

    for (int l = SIZE-2; l >= 0; l--) {
        for (int c = 0; c < l; c++) {
            triangle[l][c] += max(triangle, l+1, c);
        }
    }

    printf("max: %d", triangle[0][0] + max(triangle, 1, 0));

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}