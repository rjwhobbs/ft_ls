#include "ft_ls.h"

void	print_files(char **files)
{
	if (files)
		while (*files)
			print_name(*files++);
	ft_nl();
}
