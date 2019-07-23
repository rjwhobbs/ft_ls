#include "ft_ls.h"

static char			*ft_strrealloc(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

static void	sort_print(char ***files, char ***dirs, char *dir, char *ops)
{
	if (*dirs)
		sort(dirs, ops);
	if (*files)
		sort(files, ops);
	printdirname(dir);
	print_files_l(*files);
	ft_nl();
}

void		print_R(char *dir, char *ops)
{
	char **files;
	char **dirs;
	char *tempdir;
	char **temp2;

	if (dir[ft_strlen(dir) - 1] != '/')
		dir = ft_strrealloc(dir, "/");
	dirs = NULL;
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
