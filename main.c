#include "ft_ls.h"


// static void    checker(char **dir)
// {
//     if ((*dir)[ft_strlen(*dir) - 1] != '/') 
//         *dir = ft_strrealloc(*dir, "/");  
// }

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

void			no_ops_files(char **files)
{
	char	**strs;
	int		i;

	sort(&files, "-");
	while (*files)
	{
		i = 0;
		if (((*files)[ft_strlen(*files) - 1]) != '/')
		{
			print_name(*files++);
			ft_nl();
		}
		else
		{
			printdirname(*files);
			strs = get_filenames(*files++, '-');
			sort(&strs, "-");
			while(strs[i])
				print_name(strs[i++]);
			ft_nl();
			if (strs)
				strstr_del(&strs);
		}
	}
}

void	l_op_no_files(char *ops)
{
	char	**strs;

	strs = get_filenames("./", (ft_strchr(ops, 'a'))? 'a' : '-');
	sort(&strs, ops);
	print_files_l(strs);
	strstr_del(&strs);
}
void		no_files_ops(char *ops)
{
	char	**strs;
	int		i;

	i = 0;
	strs = get_filenames("./", (ft_strchr(ops, 'a'))? 'a' : '-');
	if (strs) 
		sort(&strs, ops);
	while(strs[i])
		print_name(strs[i++]);
	strstr_del(&strs);
}

void	l_op_files(char *ops, char **files)
{
	char	**strs;

	sort(&files, ops);
	while (*files)
	{
		if (((*files)[ft_strlen(*files) - 1]) != '/')
		{
			print_file_l(files);
			files++;
		}
		else
		{
			printdirname(*files);
			strs = get_filenames(*files++, (ft_strchr(ops, 'a'))? 'a' : '-');
			sort(&strs, ops);
			print_files_l(strs);
			strstr_del(&strs);
		}
	}
}

static void		run_func(char *ops, char ***files)
{
	char	**strs;
	char	**dirs;
	int		i;

	i = 0;
	strs = NULL;
	dirs = NULL;
	if (ops[0] && !(ft_strchr(ops, 'l')) && !*files)
		no_files_ops(ops);
	else if (!ops[0] && *files)
		no_ops_files(*files);
	else if (ft_strchr(ops, 'l') && !*files) 
		l_op_no_files(ops);
	else if (ft_strchr(ops, 'l') && *files) 
		l_op_files(ops, *files);
	if(*files)
		strstr_del(files);
	exit (0);
}

int	main(int ac, char **av)
{
	char 			*ops;
	char 			**files;
	char 			**dirs;
	int				i;
	struct stat		valid_dir;

	dirs = NULL;
	ops = NULL;
	i = 0;
	if (ac > 1)
	{
		process_args(av, &ops, &files);
		if (files && *files)
			valid_checker(files); //We still need to free files
		if (!(ft_strchr(ops, 'R')))
			run_func(ops, &files);
		else if (ft_strchr(ops, 'R') && !ft_strchr(ops, 'l'))
		{
			if (!files)
				print_rec("./", ops);
			else
				while (files[i])
					print_rec(files[i++], ops);
		}
		else if (ft_strchr(ops, 'R') && ft_strchr(ops, 'l') && files)
		{
			while(*files)
			{
				lstat(*files, &valid_dir);
				if (!(S_ISDIR(valid_dir.st_mode)))
				{
					print_file_l(files);
					(files)++;
				}
				else
				{
					print_rec(*files, ops);
					(files)++;
				}
			}
		}
	}
	else if (ac == 1)
	{
		files = get_filenames("./", '-');
		if (files)
			sort(&files, ops);
		while (*files)
		{
			print_name(*files++);
		}
	}
	return (0);
}
