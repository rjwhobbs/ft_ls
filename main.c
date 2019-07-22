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
		{
			while (files[c++])
				files[c - 2] = files[c - 1];
            files[c - 2] = NULL;
		}
		files++;
		if (c)
			files--;
    }
}

static void		run_func(char *ops, char ***files)
{
	char	**str;

	str = NULL;
	if (ft_strchr(ops, 'l') && !*files) 
	{
		str = get_filenames("./", (ft_strchr(ops, 'a'))? 'a' : '-');
		sort(&str);
		print_files_l(str);
		exit (0);
	}
	else if (ft_strchr(ops, 'l') && *files) 
	{
		sort(files);
		valid_checker(*files); //We still need to free files
		str = get_filenames(**files, (ft_strchr(ops, 'a'))? 'a' : '-');
		sort(&str);
		print_files_l(str);
		exit (0);
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
		run_func(ops, &files);
		if (ft_strchr(ops, 'R'))
			while (*files)
			{
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
