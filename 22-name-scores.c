/* Using names.txt, a 46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. 

Then working out the alphabetical value for each name, multiply this value by its 
alphabetical position in the list to obtain a name score. 

For example, when the list is sorted into alphabetical order, COLIN, which is worth 
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file? */

#include <stdio.h>
#include <time.h>
#include <string.h>

int load_names(char names[][20]) {
    int i = 0;
    FILE *file = fopen("22-names.txt", "r");
    while(!feof(file)) {
        fscanf(file, "\"%[^,],", &names[i]);
        names[i][strlen(names[i])-1] = '\0';
        //printf("%d %s\n", i, names[i]);
        i++;
    }
    fclose(file);

    return i;
}

int first_alph(char names[][20], int start) {
    int i, lesser = 0;
    for (i = start; names[i][0] != '\0'; i++) {
        if (strcmp(names[lesser], names[i]) > 0)
            lesser = i;
    }
    return lesser;
}

void selection_sort(char names[][20], int end) {
    char aux[20] = {0};
    int pos;
    for (int i = 1; i < end+1; i++) {
        pos = first_alph(names, i);
        if (i != pos) {
            strcpy(aux, names[pos]);
            strcpy(names[pos], names[i]);
            strcpy(names[i], aux);
            //printf("%d %s\n", i, names[i]);
        }
    }
}

int alphabetical_val(char *name) {
    int val = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        val += ((int)name[i] - 64);
    }
    return val;
}

int main() {

    clock_t time = clock();

    char names[10000][20] = {0};
    int end = load_names(names);
    unsigned long long scores = 0;

    selection_sort(names, end);

    for (int i = 1; i < end+1; i++) {
        scores += alphabetical_val(names[i])*i;
    }

    printf("scores: %llu", scores);

    time = clock() - time;
    printf("\n\ntime elapsed: %f", (double)(time)/CLOCKS_PER_SEC);
    return 0;
}