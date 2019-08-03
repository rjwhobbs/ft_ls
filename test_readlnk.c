#include "ft_ls.h"
#include <unistd.h>

int main(int ac, char *av[])
{
    char buf[100];
    ssize_t len;

    len = readlink(av[1], buf, 100);
    buf[len] = 0;
    ft_putendl(buf);
    return (0);
}

