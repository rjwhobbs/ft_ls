#include "ft_ls.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	char *ops;
	char **files;
	char **dirs;

	process_args(av, &ops, &files);
	if (ac)
	{
		while (*files)
		{
			if (ft_strchr(ops, 'R'))
				print_R(*files);
			else
			{
				//print_files()
			}
			
			/* code */
		}
		
	}
	return (0);
}
