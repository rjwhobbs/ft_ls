#include "fcntl.h"
#include "./libft/libft.h"
#include "ft_ls.h"

void    valid_checker(char **files)
{
    int     c;

    c = 0;
    while (*files)
    {
        c = 0;
        if (!(ft_strcmp(*files , "X")))
        {
            ft_strdel(files);
			c++;
	    }
		if (c)
		{
			while (files[c])
			{
				files[c - 1] = files[c];
				c++;
			}
            files[c - 1] = NULL;
		}
		files++;
		if (c)
			files--;
    }
}

int main(void)
{
    int i;
    int c;

    i = 0;
    char **del_me;
    char **temp;
    char **s = ft_strsplit("X X a b X X X c X d e f", ' ');
    del_me = s;
    valid_checker(s);
    while (*s)
    {
        ft_putendl(*s++);
    }
    strstr_del(&del_me);
    return (0);
}