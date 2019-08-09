#include "ft_ls.h"

static void		print_error(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}

static void		readstat(char *file)
{
	struct stat		filestat;

	if ((lstat(file, &filestat)) != -1)
	{
		print_mode(filestat);
		print_link(filestat);
		print_username(filestat);
		print_group(filestat);
		print_devid(filestat);
		print_size(filestat);
		print_time(filestat);
		print_name_l(file);
		print_sym_link(file, filestat);
		ft_nl();
	}
	else
		print_error(file);
}

void			print_file_l(char **files)
{
	readstat(*files);
	ft_nl();
}
