#include "ft_ls.h"

void	print_time(struct stat filestat)
{
	struct timespec	file_time;
	char			*str;
	time_t			current;
	int				file_year;

	file_time = filestat.st_mtimespec;
	current = time(NULL);
	file_year = ft_atoi(ctime(&file_time.tv_sec) + 20);
	if (ft_atoi(ctime(&current) + 20) > file_year)
	{
		str = ft_strsub(ctime(&file_time.tv_sec), 4, 6);
		ft_putstr(str);
		ft_putstr("  ");
		ft_putnbr(file_year);
	}
	else
	{
		str = ft_strsub(ctime(&file_time.tv_sec), 4, 12);
		ft_putstr(str);
	}
	ft_putstr(" ");
	if (str)
		ft_strdel(&str);
}
