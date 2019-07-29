#include "ft_ls.h"

int main(int ac, char *av[])
{
	struct stat 	check;
	DIR				*dir;
	struct dirent	*file;

	if ((dir = opendir(av[1])) == NULL)
		ft_putendl(strerror(errno));
	else if ((file = readdir(dir)) == NULL)
	{
		ft_putendl(strerror(errno));
	}
	int x = lstat(av[1], &check);
	ft_putnbr(x);
	ft_nl();
	if (x < 0)
		ft_putendl(strerror(errno));
	else
		ft_putendl("no error according to lstat");
	if (dir)
		closedir(dir);
	return (0);
}