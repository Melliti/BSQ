#include <stdio.h>
#include "string.h"
#include "map.h"

int main(int ac, char **av) {
    if (ac != 2)
        my_puterr("Usage: ./BSQ <filepath>\n");
    extact_map(av[1]);
    
    return 0;
}
