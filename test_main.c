#include "ft_ls.h"

void    checker(char **dir)
{
    if ((*dir)[ft_strlen(*dir) - 1] != '/') 
        *dir = ft_strrealloc(*dir, "/");  
}

int main(int ac, char *av[])
{
    char **files;
    char *ops;
    int i;

    i = 0;
    process_args(av, &ops, &files);

    while (files[i])
    {
        checker(&files[i]);
        ft_putendl(files[i]);
        i++;
    }
    strstr_del(&files);
    return (0);
}