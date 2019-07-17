#include <dirent.h>
#include "ft_ls.h"

void	print_R(char *dir)
{
	char **files;
	char **dirs;
	char *tempdir;
	char **temp2;
	char **temp3;

	if (dir)
	{
		dirs = NULL;
		files = get_filenames(dir, 'a');
		dirs = get_dirnames(dir, 'a');
		temp2 = dirs;
		temp3 = files;
		if (dirs)
			sort(&dirs);
		if (files)
			sort(&files);
		ft_putendl(dir);
		ft_nl();
		print_files_l(files);
		ft_nl();
		if (dirs)
        {
			while (*dirs)
			{
				tempdir = ft_strjoin(dir, *dirs++);
				print_R(tempdir);
				free(tempdir);
			}
		}
		strstr_del(&temp2);
		strstr_del(&temp3);
		//free(*temp2);
		//free(*temp3);
		/*TODO: Free dirs here*/
		// TODO: Free files here
	}
}
