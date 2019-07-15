#include <dirent.h>
#include "ft_ls.h"

static char **filenames_all(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;

	n = count_files(dirname, 'a');
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = files;
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL)
	{
		*files++ = ft_strdup(file->d_name);
	}
	*files = NULL;
	closedir(dir);
	files = temp;
	return (files);
}


static char **filenames(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;

	n = count_files(dirname, '-');
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = files;
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL)
	{
		if (file->d_name[0] != '.')
			*files++ = ft_strdup(file->d_name);
	}
	*files = NULL;
	closedir(dir);
	files = temp;
	return (files);
}

char **get_filenames(char *dirname, int mode)
{
	if (mode == 'a')
		return (filenames_all(dirname));
	else
		return (filenames(dirname));
}
