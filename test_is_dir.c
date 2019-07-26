#include "ft_ls.h"
#include <fcntl.h>
#include <sys/un.h>
#include <sys/socket.h>

int     main(int ac, char *av[])
{
    struct stat		validdir;

	(av)++;
	lstat(*av, &validdir);

	if (S_ISDIR(validdir.st_mode))
	{
		ft_putstr(*av);
		ft_putendl(" is a dir");
	}
	else
	{
		ft_putstr(*av);
		ft_putendl(" is not a dir");
	}
	return (0);
}