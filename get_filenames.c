#include <dirent.h>
#include "ft_ls.h"

static char **error(char *dir)
{
	ft_putstr(dir);
	ft_putendl("is not a valid directory");
	return (NULL);
}

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
	if ((dir = opendir(dirname)) == NULL)
		return (error(dirname));
	while ((file = readdir(dir)) != NULL)
		*files++ = ft_strdup(file->d_name);
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
	if ((dir = opendir(dirname)) == NULL)
		return (error(dirname));
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
