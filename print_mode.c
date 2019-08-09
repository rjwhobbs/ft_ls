#include "ft_ls.h"

void	print_mode(struct stat filestat)
{
	if (S_ISDIR(filestat.st_mode))
		ft_putchar('d');
	else if (S_ISFIFO(filestat.st_mode))
		ft_putchar('p');
	else if (S_ISBLK(filestat.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(filestat.st_mode))
		ft_putchar('c');
	else if (S_ISLNK(filestat.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(filestat.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
	print_perm(filestat);
    ft_putstr(" ");
}