#include <string.h>
#include "ft_ls.h"
#include <errno.h>

int main(int ac, char *av[])
{
    struct stat file;

    int i;
    i = stat(av[1], &file);
    if (i < 0)
        ft_putendl(strerror(errno));
    return (0);
}