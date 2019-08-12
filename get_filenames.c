#include "ft_ls.h"

static char	**filenames_all(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;
	struct stat		valid_file;

	//errno = 0;
	lstat(dirname, &valid_file);
	n = count_files(dirname, 'a');
	if (n < 0)
	{
		files = (char **)malloc(sizeof(char *) * 1);
		files[0] = NULL;
		return (files);
	}
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

static char	**filenames(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;
	struct stat		valid_file;

	//errno = 0;
	lstat(dirname, &valid_file);
	n = count_files(dirname, '-');
	if (n < 0 || !(S_ISDIR(valid_file.st_mode)))// lets try optimize this
	{
		// if (errno == 13)
		// 	return (NULL);
		files = (char **)malloc(sizeof(char *) * 2);
		files[0] = ft_strdup(dirname);
		files[1] = NULL;
		return (files);
	}
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
