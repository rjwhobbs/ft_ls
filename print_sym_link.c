#include "ft_ls.h"

void    print_sym_link(char *filename, struct stat filestat)
{
    char 		buf[1024];
    ssize_t		len;

	len = 0;
    if (S_ISLNK(filestat.st_mode))
	{
		len = readlink(filename, buf, 1024);
		buf[len] = 0;
		ft_putstr(" -> ");
		ft_putstr(buf);		
	}
}
