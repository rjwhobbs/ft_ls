#include <dirent.h>
#include "ft_ls.h"

void	print_R(char *dir)
{
	char **files;
	char **dirs;
	char *tempdir;
	char **temp2;

	if (dir)
	{
		dirs = NULL;
		files = get_filenames(dir, 'a');
		dirs = get_dirnames(dir, 'a');
		temp2 = dirs;
		if (dirs)
			sort(&dirs);
		if (files)
			sort(&files);
		ft_nl();
		ft_putendl(dir);
		ft_nl();
		print_files_l(files);
		if (dirs)
			while (*dirs)
			{
				tempdir = ft_strjoin(dir, *dirs++);
				print_R(tempdir);
				free(tempdir);
			}
		strstr_del(&temp2);
		strstr_del(&files);
	}
}
