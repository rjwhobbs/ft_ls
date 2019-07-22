#include "ft_ls.h"
#include <unistd.h>

static void 	print_error(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(strerror(errno));	
}

static void    valid_checker(char **files)
{
	struct stat		valid_file;
    int     		c;

    c = 0;
    while (*files)
    {
        c = 0;
        if ((stat(*files, &valid_file)) == -1)
        {
			print_error(*files);
            ft_strdel(files);
			c++;
	    }
		if (c)
			while (files[c])
			{
				files[c - 1] = files[c];
				c++;
			}
            files[c - 1] = NULL;
		files++;
		if (c)
			files--;
    }
}

int	main(int ac, char **av)
{
	char *ops;
	char **files;
	char **dirs;

	dirs = NULL;
	if (ac > 1)
	{
		process_args(av, &ops, &files);
		if (files)
			sort(&files);
		if (files)
			valid_checker(files); //We still need to free files.
		while (*files)
		{
			if (ft_strchr(ops, 'R'))
				print_R(*files);
			(files)++;
		}
	}
	else if (ac == 1)
	{
		files = get_filenames("./", '-');
		if (files)
			sort(&files);
		while (*files)
			print_name(*files++);
	}
	return (0);
}
