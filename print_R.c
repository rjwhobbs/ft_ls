#include <dirent.h>
#include "ft_ls.h"

void	print_R(char *dir)
{
	char **files;
	char **dirs;

	if (dir)
	{
		dirs = NULL;
		files = get_filenames(dir, 'a');
		dirs = get_dirnames(dir, 'a');
		if (dirs)
			sort(&dirs);
		if (files)
			sort(&files);
		ft_putendl(dir);
		ft_nl();
		print_files(files);
		ft_nl();
		if (dirs)
			while (*dirs)
				print_R(ft_strjoin(dir, *dirs++));
	}
}
