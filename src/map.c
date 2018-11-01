#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char *file_info(int *i, FILE *file) {
    size_t len = 0;
    char *line = NULL;
    
    while (getline(&line, &len, file) != -1)
        ++*i;
    return line;
}
int *init_map(int idx, int *map, int length) {
    int i = 0;
    
    if (idx == 0)
    {
        while (i < length)
            map[i++] = 1;
    }
    else
        map[0] = 1;
    return map;
}
int extact_map(char *map)
{
    int nb_lines = 0;
    int it = 0;
    int **tab;
    char *line = NULL;
    FILE *file;
    
    file = fopen(map, "r");
    if (file == NULL)
        my_puterr("file does not exist");
    line = file_info(&nb_lines, file);
    tab = malloc(sizeof(int) * nb_lines + 2);
    printf("[] %d\n", nb_lines);
    int size = my_strlen(line);
    while (it <= nb_lines)
    {
        printf("%d\n", it);
        tab[it] = malloc(sizeof(int) * size + 1);
        init_map(it, tab[it], size);
        it++;
    }
    tab[nb_lines + 1] = NULL;
    free(line);
    fill_array(file, tab, size);
    fclose(file);
}