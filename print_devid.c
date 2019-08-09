#include "ft_ls.h"

void	print_devid(struct stat filestat)
{
	u_int32_t	maj;
	int32_t		min;

	if (S_ISBLK(filestat.st_mode) || S_ISCHR(filestat.st_mode))
	{
		maj = major(filestat.st_rdev);
		min = minor(filestat.st_rdev);
		if (min <= 255)
		{
			ft_putnbr(maj);
			ft_putstr(",\t");
			ft_putnbr(min);
			ft_putstr("\t");
		}
		else
		{
			ft_putnbr(maj);
			ft_putstr(", ");
			ft_print_hex(min);
			ft_putstr("  ");
		}
	}
}
