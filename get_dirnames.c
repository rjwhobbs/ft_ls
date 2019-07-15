#include <dirent.h>
#include "ft_ls.h"

static char **dirnames(char *parentdir)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**dirs;
	char			**temp;

	n = count_files(dirname, mode);
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = dirs;
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL)
		if (file->d_type == DT_DIR) // This line is a key
			if (file->d_name[0] != '.')
			{
				*dirs = ft_strdup(file->d_name);
				*dirs = ft_strjoin(*dirs, "/");
				dirs++
			}
	*dirs = NULL;
	closedir(dir);
	dirs = temp;
	return (dirs);
}

static char **dirnames_all(char *parentdir)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**dirs;
	char			**temp;

	n = count_dirs(paretdir, 'a');
	dirs = (char **)malloc(sizeof(char *) * (n + 1));
	temp = dirs;
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL)
		if (file->d_type == DT_DIR) // This line is a key
		{
			*dirs = ft_strdup(file->d_name);
			*dirs = ft_strjoin(*dirs, "/");
			dirs++
		}
	*dirs = NULL;
	closedir(dir);
	dirs = temp;
	return (dirs);
}

char **get_dirnames(char *parentdir, int mode)
{
	if (mode = 'a')
		return (dirnames_all(parentdir));
	else
		return (dirnames(parentdir));
}
