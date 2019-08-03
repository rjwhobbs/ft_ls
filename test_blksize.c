#include "libft/libft.h"
#include <sys/stat.h>

int main(int ac, char *av[])
{
    struct stat filestat;

    lstat(av[1], &filestat);
    ft_putnbr(filestat.st_blocks);
    ft_nl();
    return (0);
}