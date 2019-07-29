#include "ft_ls.h"
#include <fcntl.h>
#include <sys/un.h>
#include <sys/socket.h>

int     main(int ac, char *av[])
{
    struct stat		validdir;
	DIR				*dir;
	struct dirent	*file;

	(av)++;
	lstat(*av, &validdir);

	dir = opendir(*av);
	if (S_ISDIR(validdir.st_mode))
	{
		ft_putstr(*av);
		ft_putendl(" is a dir according to S_ISDIR");
	}
	else if (!S_ISDIR(validdir.st_mode))
	{
		ft_putstr(*av);
		ft_putendl(" is not a dir according to S_ISDIR");
	}
	file = readdir(dir);
	if (file->d_type == DT_DIR)
	{
		ft_putstr(*av);
		ft_putendl(" is a dir according to DT_DIR");
	}
	else
	{
		ft_putstr(*av);
		ft_putendl(" is not a dir according to DT_DIR");
	}
	if (validdir.st_mode & S_IFDIR)
	{
		ft_putstr(*av);
		ft_putendl(" is a dir according to S_IFDIR");
	}
	else
	{
		ft_putstr(*av);
		ft_putendl(" is not a dir according to S_IFDIR");
	}
	closedir(dir);
	return (0);
}