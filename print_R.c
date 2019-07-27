#include "ft_ls.h"

static void	sort_print(char ***files, char ***dirs, char *dir, char *ops)
{
	if (*dirs)
		sort(dirs, ops);
	if (*files)
		sort(files, ops);
	printdirname(dir);
	print_files_l(*files);
}

void		print_R(char *dir, char *ops)
{
	char **files;
	char **dirs;
	char *tempdir;
	char **temp2;

	files = get_filenames(dir, 'a');
	dirs = get_dirnames(dir, 'a');
	temp2 = dirs;
	sort_print(&files, &dirs, dir, ops);		
	if (dirs)
		while (*dirs)
		{
			tempdir = ft_strjoin(dir, *dirs++);
			print_R(tempdir, ops);
			free(tempdir);
		}
	if (temp2)
		strstr_del(&temp2);
	strstr_del(&files);
}
