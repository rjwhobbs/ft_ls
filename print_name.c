#include "ft_ls.h"

void	print_name(char *file)
{
	char *name_ptr;

	if ((name_ptr = ft_strrchr(file, '/')))
		ft_putendl(name_ptr + 1);
	else
		ft_putendl(file);
}
