#include "ft_ls.h"

void	print_time(struct stat filestat)
{
	struct timespec	time;
	char			*str;

	time = filestat.st_mtimespec;
	str = ft_strsub(ctime(&time.tv_sec), 4, 12);
	ft_putstr(str);
	ft_putstr(" ");
	ft_strdel(&str);
}