#include "ft_ls.h"

int main(int ac, char *av[])
{
	struct stat file;

	lstat(av[1], &file);
	if (S_ISLNK(file.st_mode))
		ft_putendl("Link");
	return (0);
}