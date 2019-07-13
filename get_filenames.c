#include <dirent.h>
#include "ft_ls.h"

char **get_filenames(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;

	n = count_files(dirname);
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
