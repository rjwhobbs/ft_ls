#include <sys/stat.h>
#include <dirent.h>
#include "libft/libft.h"

int main(int ac, char *av[])
{
    DIR *dir;
    struct dirent *file;

    dir = opendir(av[1]);
    if (dir == NULL)
        ft_putendl("dir is null");
    while ((file = readdir(dir)) != NULL) //This causes a segfault if passed a dir pointer
    {                                     //that is NULL.
        ft_putendl("This happened");
    }
    ft_nl();
    return (0);
}