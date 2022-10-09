/* Find the greatest product of four adjacent numbers in the same direction
(up, down, left, right, or diagonally) in the 20×20 grid. */

#include <stdio.h>

#define SIZE 20

// Matrix containing the grid
int grid[SIZE][SIZE] = {0};

// Reads grid from the file "010-grid.txt"
void read_grid() {
    FILE* file = fopen("010-grid.txt", "r");
    if (!file) {
        printf("ERR: Couldn't open file.");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(file, "%d", &grid[i][j]);
        }
    }
    fclose(file);
}

void compares(long prod, long *largest) {
    if (prod > *largest) {
        *largest = prod;
    }
}

/* Searches the grid from an initial point (i, j) point to 
(i+3(incI), j+3(incJ)). incI and incJ should be 0, 1 or -1 */
long search_direction(int i, int j, int incI, int incJ) {
    int a, b, c, d;

    // If the last value is out of the boundaries, returns -1
    if (i+3*(incI) > SIZE || j+3*(incJ) > SIZE
        || i+3*(incI) < 0 || j+3*(incJ) < 0)
        return 0;

    a = grid[i][j];
    b = grid[i+1*(incI)][j+1*(incJ)];
    c = grid[i+2*(incI)][j+2*(incJ)];
    d = grid[i+3*(incI)][j+3*(incJ)];

    return a*b*c*d;
}

// Finds the largest value in an 8-position array
long largest_val(long values[8]) {
    long largest = values[0];
    for (int i = 1; i < 8; i++) {
        compares(values[i], &largest);
    }
    return largest;
}

int main() {

    long largest;

    int i, j;
    long prod;

    read_grid();
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            prod = largest_val((long[8])
                                {search_direction(i, j, 0, 1),   // right
                                search_direction(i, j, 0, -1),   // left
                                search_direction(i, j, -1, 0),   // up
                                search_direction(i, j, 1, 0),    // down
                                search_direction(i, j, -1, -1),  // diag. 1
                                search_direction(i, j, 1, 1),    // diag. 2
                                search_direction(i, j, 1, -1),   // diag. 3
                                search_direction(i, j, -1, 1)}); // diag. 4
            if (prod < 96000000) // Maximum possible value is 99^4
                compares(prod, &largest);
        }
    }

    printf("%d", largest);

    return 0;
}