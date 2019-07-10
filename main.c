#include "libft/libft.h"

static int process_flags(char **av, char *op);
static int	process_files(int ac, char **av, char ***files, int i);

void errors(char op)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(op);
	ft_nl();
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
}

int	process_args(int ac, char **av, char *op, char ***files)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = process_flags(&av[i], op);
		if (!j)
			break ;
		i++;
	}
	i = process_files(ac, av, files, i);
	if (i == -1)
		return (-1);
	return (0);
}

static int isflag(char c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 't' || c == 'R')
		return (1);
	return (0);
}

static int process_flags(char **av, char *op)
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
		else if (av[i][j] == 'l' && !(*op & 2))
			*op += 2;
		else if (av[i][j] == 'r' && !(*op & 4))
			*op += 4;
		else if (av[i][j] == 't' && !(*op & 8))
			*op += 8;
		else if (av[i][j] == 'R' && !(*op & 16))
			*op += 16;
		j++;
	}
	if (!(av[i][j]))
		return (1);
	else 
	{
		errors(av[i][j]);
		return (0);
	}
	return (0);
}

static int	process_files(int ac, char **av, char ***files, int i)
{
	int j;

	j = 0;
	if (i < ac)
	{
		*files = (char **)malloc(sizeof(char *) * (ac - i + 1));
		if (!*files)
			return (-1);
		while (i < ac)
		{
			files[0][j++] = ft_strdup(av[i++]);
			if (files[0][j - 1] == NULL)
				return (-1);
		}
		files[0][j] = NULL;
	}
	return (i);
}

int main(int ac, char **av)
{
	//char *flags;
	char **files;
	char op;
	int i;

	op = 0;
	i = 1;
	process_args(ac, av, &op, &files);
	ft_putnbr(op);
	ft_nl();
	while(*files)
		ft_putendl(*files++);
	return (0);
}