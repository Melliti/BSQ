#include <stdio.h>
#include <stdlib.h>

void print_line(int *nb, int size) {
    int i = 0;
    while (i <= size)
        printf("> %d ", nb[i++]);
    printf("\n");
}

void fill_array(char *map, int **tab, int size) {
    FILE *file;
    int x = 1;
    int y = 1;
    size_t len = 0;
    char *line = NULL;
    
    file = fopen(map, "r");
    if (file == NULL)
        my_puterr("file does not exist");
    //print_line(tab[0], size);
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
            print_line(tab[y], size);
            y++;
            x = 1;
        }
        
}