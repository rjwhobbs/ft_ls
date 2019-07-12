#include "libft/libft.h"

static void		errors(char op)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(op, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-Ralrt] [file ...]", 2);
	exit (0);
}

static int		isflag(char c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 't' || c == 'R')
		return (1);
	return (0);
}

char			*process_flags(char **av[])
{
	char *op;
	char *op_position;

	op = ft_strnew(5);
	op_position = op;
	(*av)++;
	while (op_position && **av && ***av == '-')
	{
		(**av)++;
		if (***av == '-' && !((**av)[1]))
			break ;
		while (**av && isflag(***av))
		{
			if (!ft_strchr(op_position, ***av))
				*op++ = ***av;
			(**av)++;
		}
		if (!***av)
			(*av)++;
		else if (***av)
			errors(***av);
	}
	return (op_position);
}