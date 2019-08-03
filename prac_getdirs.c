#include "./libft/libft.h"
#include "ft_ls.h"

int     main(int ac, char *av[])
{
    char **s;

    s = get_dirnames("." , 'a');
    while(*s)
    {
        ft_putendl(*s++);
    }
    return (0);
}
