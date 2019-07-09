#include "libft/libft.h"

int isflag(int c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 'R' || c == 't')
		return (1);
	return (0);
}

int process_args(int ac, char **av, char **flags)
{
	int i = 1;
	int j = 0;

	*flags = ft_strnew(5);
	while (i < ac)
	{
		if(av[i][j++] == '-')
		{
			while (av[i][j])
			{
				if (isflag(av[i][j]))
					ft_strncat(*flags, av[i] + j++, 1);
				else
					return (-1);
			}
		}
		else
			break;
		j = 0;
		i++;
	}
	return (i);
}

int main(int ac, char **av)
{
	char *flags;
	char **dirs;

	if (ac > 1)
	process_args(ac, av, &flags);

	while (*flags)
	{
		ft_putchar(*flags++);
		ft_nl();
	}
	/*
	while(*dirs)
		ft_putendl(*dirs++);
	*/
	//ft_strdel(&flags);
	return (0);
}
