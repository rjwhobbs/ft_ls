#include <dirent.h>
#include "ft_ls.h"

static void	sort_print(char ***files, char ***dirs)
{
	if (*dirs)
		sort(dirs);
	if (*files)
		sort(files);
}

void		print_R(char *dir)
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
		sort_print(&files, &dirs);
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
