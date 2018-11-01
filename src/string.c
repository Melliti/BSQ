#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 

int my_strlen(char *str)
{
    if (str == NULL)
    {
        my_puterr("[MY_STRLEN ERR] Null string\n");
        return 84;
    }
    int i = 0;

    while (*str)
    {
        ++i;
        *str++;
    }
    return i;
}

int my_puterr(char *str)
{
    if (str == NULL)
    {
        my_puterr("[MY_PUTERR ERR] Null string\n");
        return 84;
    }
    int i = write(STDERR_FILENO, str, my_strlen(str));
    exit(EXIT_FAILURE);
}

int my_putstr(char *str)
{
    if (str == NULL)
    {
        my_puterr("[MY_PUTSTR ERR] Null string\n");
        return 84;
    }
    int i = write(STDOUT_FILENO, str, my_strlen(str));
    return i;
}