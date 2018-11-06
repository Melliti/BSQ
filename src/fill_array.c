#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void print_line(int *nb, int size) {
    int i = 0;
    while (i <= size)
        printf("| %d ", nb[i++]);
    printf("\n");
}

int **fill_array(char *map, int **tab, int size) {
    FILE *file;
    int x = 1;
    int y = 1;
    size_t len = 0;
    char *line = NULL;
    
    if ((file = fopen(map, "r")) == NULL)
        my_puterr("file does not exist");
    while (getline(&line, &len, file) != -1)
        {
            while (x <= size)
            {
                if (line[x - 1] == '.')
                    tab[y][x] = 1;
                else
                    tab[y][x] = 0;
                x++;
            }
            y++;
            x = 1;
        }
    return tab;
}