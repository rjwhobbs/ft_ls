#include "ft_ls.h"

static void		print_error(void)
{
	if (errno == 13)
	{
		ft_putstr("ft_ls: ");
		//ft_putstr(file);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
	}
	errno = 0;
}

int				count_files(char *dirname, int mode)
{
	DIR				*dir;
	struct dirent	*file;
	int				n;

	n = 0;
	dir = opendir(dirname);
	if (dir == NULL)
	{
		print_error();
		return (-1);
	}
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
