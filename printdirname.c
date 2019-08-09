#include "ft_ls.h"

void	printdirname(char *dir)
{
	char *last_slash;
	char *temp;

	temp = dir;
	if ((last_slash = ft_strrchr(dir, '/')))
		if (!(ft_strequ(dir, "./")))
		{
			while (temp < last_slash)
				ft_putchar(*temp++);
			ft_putendl(":");
		}
}
