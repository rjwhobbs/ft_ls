#include <dirent.h>
#include "ft_ls.h"

void	print_rec_test(char *dir)
{
	char **files;
	char **dirs;
	char *tempdir;

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
		print_files_l(files);
		ft_nl();
        // if (dirs)
        //     tempdir = ft_strjoin(dir, *dirs++);
		if (dirs)
			while (*dirs)
			{
				tempdir = ft_strjoin(dir, *dirs++);
				print_R(tempdir);
				free(tempdir);
			}
	}
}