#include "libft/libft.h"

int isflag(char c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 't' || c == 'R')
		return (1);
	return (0);
}

int process_flags(char **av, char *op)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (av[i][j] == '-')
		j++;
	while ((av[i][j]) && isflag(av[i][j]))
	{
		if (av[i][j] == 'a' && !(*op & 1))
			*op += 1;
		if (av[i][j] == 'l' && !(*op & 2))
			*op += 2;
		if (av[i][j] == 'r' && !(*op & 4))
			*op += 4;
		if (av[i][j] == 't' && !(*op & 8))
			*op += 8;
		if (av[i][j] == 'R' && !(*op & 16))
			*op += 16;
		j++;
	}
	if (!(av[i][j]))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	char *flags;
	char **dirs;
	char op;
	int i;

	op = 0;
	i = 1;


	if (av[1][0] == '-')
		while (i < ac)
		{
			process_flags(&av[i], &op);
			i++;
		}

	ft_putnbr(op);

	return (0);
}


iiiiiiiiiiii