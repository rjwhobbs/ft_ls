#include "ft_ls.h"

static void	print_sticky(struct stat filestat)
{
	if ((filestat.st_mode & S_IXOTH) && (filestat.st_mode & S_ISVTX))
		ft_putchar('t');
	else if (!(filestat.st_mode & S_IXOTH) && (filestat.st_mode & S_ISVTX))
		ft_putchar('T');
	else if ((filestat.st_mode & S_IXOTH) && !(filestat.st_mode & S_ISVTX))
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void	print_ssgrp(struct stat filestat)
{
	if ((filestat.st_mode & S_IXGRP) && (filestat.st_mode & S_ISGID))
		ft_putchar('s');
	else if (!(filestat.st_mode & S_IXGRP) && (filestat.st_mode & S_ISGID))
		ft_putchar('S');
	else if ((filestat.st_mode & S_IXGRP) && !(filestat.st_mode & S_ISGID))
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void	print_ssuid(struct stat filestat)
{
	if ((filestat.st_mode & S_IXUSR) && (filestat.st_mode & S_ISUID))
		ft_putchar('s');
	else if (!(filestat.st_mode & S_IXUSR) && (filestat.st_mode & S_ISUID))
		ft_putchar('S');
	else if ((filestat.st_mode & S_IXUSR) && !(filestat.st_mode & S_ISUID))
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		print_perm(struct stat filestat)
{
	ft_putstr((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((filestat.st_mode & S_IWUSR) ? "w" : "-");
	print_ssuid(filestat);
    ft_putstr((filestat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((filestat.st_mode & S_IWGRP) ? "w" : "-");
	print_ssgrp(filestat);
    ft_putstr((filestat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((filestat.st_mode & S_IWOTH) ? "w" : "-");
	print_sticky(filestat);
}