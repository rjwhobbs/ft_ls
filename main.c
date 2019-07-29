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

void			noflags_args(char ***files, char *ops)
{
	char	**strs;
	int		i;

	i = 0;
	sort(files, ops);
	while (**files)
	{
		i = 0;
		ft_putstr(**files);
		ft_putendl(":");
		strs = get_filenames(*(*files)++, '-');
		if (strs)
		{
			sort(&strs, ops);
			while(strs[i])
			{
				print_name(strs[i++]);
				ft_nl();
			}
			ft_nl();
		}
		if (strs)
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
	if (ops[0] && !(ft_strchr(ops, 'l')) && !*files)
	{
		strs = get_filenames("./", (ft_strchr(ops, 'a'))? 'a' : '-');
		if (strs) 
			sort(&strs, ops);
		while(strs[i])
		{
			print_name(strs[i++]);
			ft_nl();
		}
		strstr_del(&strs);
		exit (0);
	}
	else if (!ops[0] && *files)
		noflags_args(files, ops);
	else if (ft_strchr(ops, 'l') && !*files) 
	{
		strs = get_filenames("./", (ft_strchr(ops, 'a'))? 'a' : '-');
		sort(&strs, ops);
		print_files_l(strs);
		exit (0);
	}
	else if (ft_strchr(ops, 'l') && *files) 
	{
		sort(files, ops);
		while (**files)
		{
			printdirname(**files);
			strs = get_filenames(*(*files)++, (ft_strchr(ops, 'a'))? 'a' : '-');
			sort(&strs, ops);
			print_files_l(strs);
			strstr_del(&strs);
		}
		exit (0);
	}
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
				print_R("./", ops);
			else
				while (files[i])
				{
					//checker(&files[i]);
					print_R(files[i], ops);
					i++;
				}
		}
		else if (ft_strchr(ops, 'R') && ft_strchr(ops, 'l') && files)
		{
			while(*files)
			{
				lstat(*files, &valid_dir);
				if (!(S_ISDIR(valid_dir.st_mode)))
				{
					print_files_l(files);
					(files)++;
				}
				else
				{
					print_R(*files, ops);
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
			ft_nl();
		}
	}
	return (0);
}
