#include "ft_ls.h"

void	print_files(char **files)
{
	if (files)
		while (*files)
			ft_putendl(*files++);
}
