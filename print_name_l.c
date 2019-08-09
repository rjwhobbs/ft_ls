#include "ft_ls.h"

void	print_name_l(char *file)
{
	char *name_ptr;

	if ((name_ptr = ft_strrchr(file, '/')))
		ft_putstr(name_ptr + 1);
	else
		ft_putstr(file);
}
