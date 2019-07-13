#include <dirent.h>
#include "ft_ls.h"

int count_files(char *dirname)
{
	DIR	*dir;
	int	n;

	n = 0;
	dir = opendir(dirname);
	if (dir == NULL)
		return -1;
	while (readdir(dir))
		n++;
	closedir(dir);
	return (n);
}
