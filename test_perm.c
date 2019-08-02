#include "ft_ls.h"

void		print_perm(struct stat filestat);

int main(int ac, char *av[])
{
	struct stat 	filestat;

	lstat(av[1], &filestat);
	print_perm(filestat);
	// if ((filestat.st_mode & S_IXUSR) && (filestat.st_mode & S_ISUID))
	// 	ft_putchar('s');
	// else if (!(filestat.st_mode & S_IXUSR) && (filestat.st_mode & S_ISUID))
	// 	ft_putchar('S');
	// else if ((filestat.st_mode & S_IXUSR) && !(filestat.st_mode & S_ISUID))
	// 	ft_putchar('x');
	// else
	// 	ft_putchar('-');
	// if ((filestat.st_mode & S_IXGRP) && (filestat.st_mode & S_ISGID))
	// 	ft_putchar('s');
	// else if (!(filestat.st_mode & S_IXGRP) && (filestat.st_mode & S_ISGID))
	// 	ft_putchar('S');
	// else if ((filestat.st_mode & S_IXGRP) && !(filestat.st_mode & S_ISGID))
	// 	ft_putchar('x');
	// else
	// 	ft_putchar('-');
	// if ((filestat.st_mode & S_IXOTH) && (filestat.st_mode & S_ISVTX))
	// 	ft_putchar('t');
	// else if (!(filestat.st_mode & S_IXOTH) && (filestat.st_mode & S_ISVTX))
	// 	ft_putchar('T');
	// else if ((filestat.st_mode & S_IXOTH) && !(filestat.st_mode & S_ISVTX))
	// 	ft_putchar('x');
	// else
	// 	ft_putchar('-');
	 ft_nl();
	return (0);
}