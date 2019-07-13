#include "libft/libft.h"

int	process_args(char *av[], char **operations, char **files[]);

int main(int ac, char **av)
{
	char	**files;
	char	*op;
	int		status;

	op = NULL;
	if (ac > 1)
	{
		status = process_args(av, &op, &files);
		if (op && *op)
		{
			ft_putstr("Your current flags: ");
			ft_putendl(op);
		}
		else if (!*op)
			ft_putendl("You dont have any flags.");
		else if (!op)
			return (-1);
		while (*files)
			ft_putendl(*files++);
	}
	else if (ac == 1)
		ft_putstr("You have not given arguments.");

	return (0);
}
