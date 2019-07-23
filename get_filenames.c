#include "ft_ls.h"

static char			*ft_strrealloc(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

static char **filenames_all(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;
	

	n = count_files(dirname, 'a');
	if (n < 0)
	{
		files = (char **)malloc(sizeof(char *) * 2);
		files[0] = ft_strdup(dirname);
		files[1] = NULL;
		return (files);
	}
	if (dirname[ft_strlen(dirname) - 1] != '/')
		dirname = ft_strrealloc(dirname, "/");
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = files;
	dir = opendir(dirname);
	while ((file = readdir(dir)) != NULL)
		*files++ = ft_strjoin(dirname, file->d_name);
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
	if (n < 0)
	{
		files = (char **)malloc(sizeof(char *) * 2);
		files[0] = ft_strdup(dirname);
		files[1] = NULL;
		return (files);
	}
	if (dirname[ft_strlen(dirname) - 1] != '/')
		dirname = ft_strrealloc(dirname, "/");
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = files;
	dir = opendir(dirname);
	while ((file = readdir(dir)) != NULL)
	{
		if (file->d_name[0] != '.')
			*files++ = ft_strjoin(dirname, file->d_name);
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
