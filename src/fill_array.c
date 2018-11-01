#include <stdio.h>
#include <stdlib.h>

void fill_array(FILE *file, int **tab, int size) {
    int x = 1;
    int y = 1;
    
    while (tab[y] != NULL)
    {
        while (x < size)
        {
            tab[y][x] = 0;
            x++;
        }
        y++;
        x = 1;
    }
}