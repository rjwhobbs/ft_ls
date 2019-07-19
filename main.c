#include "ft_ls.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	char *ops;
	char **files;
	char **dirs;

	dirs = NULL;
	process_args(av, &ops, &files);
	if (ac > 1)
	{
		while (*files)
		{
			if (ft_strchr(ops, 'R'))
				print_R(*files);
			(files)++;
		}
		
	}
	return (0);
}
