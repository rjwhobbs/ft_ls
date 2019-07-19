#include <dirent.h>
#include "ft_ls.h"

int count_files(char *dirname, int mode)
{
	DIR	*dir;
	struct dirent *file;
	int	n;

	n = 0;
	dir = opendir(dirname);
	if (dir == NULL)
		return -1;
	if (mode == 'a')
		while (readdir(dir))
			n++;
	else
		while ((file = readdir(dir)) != NULL)
			if (file->d_name[0] != '.')
				n++;
	closedir(dir);
	return (n);
}
