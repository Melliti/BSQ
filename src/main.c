#include <stdio.h>
#include "string.h"
#include "map.h"

int main(int ac, char **av) {
    if (ac != 2)
        my_puterr("Usage: ./BSQ <filepath>\n");
    if (extact_map(av[1]) < 0)
        return 84;
    
    return 0;
}
