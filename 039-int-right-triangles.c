/* If p is the perimeter of a right angle triangle with integral length sides, 
{a,b,c}, there are exactly three solutions for p = 120.
    {20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised? 

p = a + b + c
right triangle: a² + b² = c² 
p = a + b + sqrt(a² + b²) */

#include <stdio.h>
#include <time.h>
#include <math.h>

int solutions(int p) {
    int solutions = 0;
    for (int a = 2; a < p/2; a++) {
        for (int b = 1; b < a && a+b < p; b++) {
            if (a + b + sqrt(a*a+b*b) == p)
                solutions++;
        }
    }
    return solutions;
}

int main() {

    clock_t time = clock();

    int s, max[2] = {0};

    for (int p = 10; p <= 1000; p++) {
        s = solutions(p);
        if (s > max[0]) {
            max[0] = s;
            max[1] = p;
        }
    }

    printf("max is %d with %d solutions", max[1], max[0]);

    printf("\n\ntime elapsed: %f", (double)(clock() - time)/CLOCKS_PER_SEC);
    return 0;
}