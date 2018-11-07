#include <stdlib.h>
#include <stdio.h>
void print_line(int *nb, int size);

int is_obstacle(int minusX, int minusY, int minusXY)
{
    if (minusX == 0 || minusY == 0 || minusXY == 0)
        return 1;
    return 0;
}

int lower_value(int minusX, int minusY, int minusXY)
{
    int i = minusX;
    if (i > minusY)
        i = minusY;
    if (i > minusXY)
        i = minusXY;
    return (i + 1);
}

void neg(int **tab, int y, int x, int length)
{
    int tmp = x;
    int limit_y = y - tab[y][x];
    int limit_x = x - tab[y][x];
    
    while (y >= limit_y)
    {
        while (tmp != limit_x)
        {
            tab[y][tmp] = -1;
            tmp--;
        }
        print_line(tab[y], length);
        tmp = x;
        y--;
    }
}

void find_higher(int **tab, int size, int length)
{
    int i = 0;
    int tmp;
    int hx;
    int hy;
 
    while (size >= 0)
    {
        tmp = length;
        while (tmp >= 0)
        {
            if (i <= tab[size][tmp])
            {
                i = tab[size][tmp];
                hx = tmp;
                hy = size;
            }
            tmp--;
        }
        size--;
    }
    neg(tab, hy, hx, length);
}

void solver(int **tab, int size, int length)
{
    int y = 1;
    int x = 1;
    char **map;
    
    map = malloc(sizeof(char *) * (size + 1));
    map[size] = NULL;
    while (y <= size)
    {
        map[y] = malloc(sizeof(char) * (length + 1));
        map[y][length] = '\0';
        while (x != length)
        {
            if (tab[y][x] != 0)
                tab[y][x] = lower_value(tab[y][x - 1], tab[y - 1][x], tab[y - 1][x - 1]);
            x++;
        }
        x = 0;
        //print_line(tab[y], length);
        y++;
    }
    find_higher(tab, size, length);
}