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
			while (files[c])
			{
				files[c - 1] = files[c];
				c++;
			}
            files[c - 1] = NULL;
		}
		files++;
		if (c)
			files--;
    }
}

void			noflags_args(char ***files)
{
	char	**strs;
	int		i;

	i = 0;
	sort(files);
	valid_checker(*files); //We still need to free files
	while (**files)
	{
		i = 0;
		ft_putstr(**files);
		ft_putendl(":");
		strs = get_filenames(*(*files)++, '-');
		sort(&strs);
		while(strs[i])
			print_name(strs[i++]);
		ft_nl();
		strstr_del(&strs);
	}
	exit (0);
}

static void		run_func(char *ops, char ***files)
{
	char	**strs;
	char	**dirs;
	int		i;

	i = 0;
	strs = NULL;
	dirs = NULL;
	if (!ops[0] && *files)
		noflags_args(files);
	else if (ft_strchr(ops, 'l') && !*files) 
	{
		strs = get_filenames("./", (ft_strchr(ops, 'a'))? 'a' : '-');
		sort(&strs);
		print_files_l(strs);
		exit (0);
	}
	else if (ft_strchr(ops, 'l') && *files) 
	{
		sort(files);
		valid_checker(*files); //We still need to free files
		strs = get_filenames(**files, (ft_strchr(ops, 'a'))? 'a' : '-');
		sort(&strs);
		print_files_l(strs);
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
		if (*files)
			valid_checker(files);
		if (!(ft_strchr(ops, 'R')))
			run_func(ops, &files);
		else if (ft_strchr(ops, 'R'))
		{
			while (*files)
			{
				print_R(*files);
				(files)++;
			}
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
