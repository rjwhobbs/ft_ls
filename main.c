#include "libft/libft.h"

char *process_flags(char **av[]);
//static int	process_files(int ac, char **av, char ***files, int i);

/* int	process_args(int ac, char **av, char *op, char ***files)
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
} */

// static int	process_files(int ac, char **av, char ***files, int i)
// {
// 	int j;

// 	j = 0;
// 	if (i < ac)
// 	{
// 		*files = (char **)malloc(sizeof(char *) * (ac - i + 1));
// 		if (!*files)
// 			return (-1);
// 		while (i < ac)
// 		{
// 			files[0][j++] = ft_strdup(av[i++]);
// 			if (files[0][j - 1] == NULL)
// 				return (-1);
// 		}
// 		files[0][j] = NULL;
// 	}
// 	return (i);
// }


int main(int ac, char **av)
{
//	char **files;
	char *op;

	op = NULL;
	if (ac > 1)
	{
		op = process_flags(&av);
		if (op && *op)
		{
			ft_putstr("Your current flags: ");
			ft_putendl(op);
		}
		else if (!*op)
			ft_putendl("You dont have any flags.");
		else if (!op)
			return (-1);
	}
	else if (ac == 1)
		ft_putstr("You have not given arguments.");
	if (!*op)
		ft_strdel(&op);
	return (0);
}