#include "ft_ls.h"

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
        if ((lstat(*files, &valid_file)) == -1)
        {
			print_error(*files);
            ft_strdel(files);
			c++;
	    }
		else if (S_ISDIR(valid_file.st_mode) && ((*files)[ft_strlen(*files) - 1]) != '/')
			*files = ft_strrealloc(*files, "/");
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
	if (ops[0] && !(ft_strchr(ops, 'l')) && !*files)
		no_files_ops(ops);
	else if (!ops[0] && *files)
		no_ops_files(*files);
	else if (ft_strchr(ops, 'l') && !*files) 
		l_op_no_files(ops);
	else if (ft_strchr(ops, 'l') && *files) 
		l_op_files(ops, *files);
	else if (!(ft_strchr(ops, 'l')) && *files)
		ops_files_no_l(ops, *files);
	if(*files)					// Freeing must be done by main, not here.
		strstr_del(files);
	exit (0);
}

static void		rec_run_func(char *ops, char **files)
{
	if (!ft_strchr(ops, 'l'))
	{
		if (!files)
			rec_no_files_no_l(ops);
		else if (files)
			rec_files_no_l(ops, files);
	}
	else if (ft_strchr(ops, 'l'))
	{
		if (!files)
			rec_no_files_l(ops);
		else 
			rec_files_l(ops, files);
	}
}

int	main(int ac, char **av)
{
	char 			*ops;
	char 			**files;

	ops = NULL;
	if (ac > 1)
	{
		process_args(av, &ops, &files);
		if (files && *files)
			valid_checker(files); //We still need to free files
		if (!(ft_strchr(ops, 'R')))
			run_func(ops, &files);
		else if (ft_strchr(ops, 'R'))
			rec_run_func(ops, files);
	}
	else if (ac == 1)
	{
		files = get_filenames("./", '-');
		if (files)
			sort(&files, ops);
		while (*files)
			print_name(*files++);
	}
	return (0);
}
