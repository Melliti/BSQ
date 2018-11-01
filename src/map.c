#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/* TO-DO
**
** store map into char**
** 
**
*/

int extact_map(char *map)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    int it = 0;
    int **tab;
    
    file = fopen(map, "r");
    if (file == NULL)
        my_puterr("file does not exist");
        
    while (getline(&line, &len, file) != -1) {
        ++i;
        printf("%s", line);
    }
    
    tab = malloc(sizeof(int) * i);
    tab[i] = NULL;
    while (it != i)
    {
        printf("%d\n", it);
        tab[it] = malloc(sizeof(int) * my_strlen(line));
        it++;
    }
}