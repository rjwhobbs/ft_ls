#include "libft/libft.h"

static void		errors(char op)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(op);
	ft_nl();
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
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