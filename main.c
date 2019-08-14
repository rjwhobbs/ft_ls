#include "ft_ls.h"

static void	print_error(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
	errno = 0;
}

static void	valid_checker(char **fs)
{
	struct stat		f;
	int     		c;

	while (*fs)
	{
		c = 0;
		if ((lstat(*fs, &f)) == -1)
		{
			print_error(*fs);
			ft_strdel(fs);
			c++;
		}
		else if (S_ISDIR(f.st_mode) && ((*fs)[ft_strlen(*fs) - 1]) != '/')
			*fs = ft_strrealloc(*fs, "/");
		if (c)
		{
			while (fs[c++])
				fs[c - 2] = fs[c - 1];
			fs[c - 2] = NULL;
		}
		fs++;
		if (c)
			fs--;
	}
}

static void	run_func(char *ops, char **files)
{
	if (ops[0] && !(ft_strchr(ops, 'l')) && !files)
		no_files_ops(ops);
	else if (!ops[0] && files)
		no_ops_files(files);
	else if (ft_strchr(ops, 'l') && !files)
		l_op_no_files(ops);
	else if (ft_strchr(ops, 'l') && files)
		l_op_files(ops, files);
	else if (!(ft_strchr(ops, 'l')) && files)
		ops_files_no_l(ops, files);
}

static void	rec_run_func(char *ops, char **files)
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

static void	deleter(char ***files, char **ops)
{
	if (ops && *ops)
		free(*ops);
	if (files && *files)
		strstr_del(files);
}

int			main(int ac, char **av)
{
	char		*ops;
	char		**files;
	static int	i;

	ops = NULL;
	if (ac > 1)
	{
		process_args(av, &ops, &files);
		if (files && *files)
			valid_checker(files);
		if (!(ft_strchr(ops, 'R')))
			run_func(ops, files);
		else
			rec_run_func(ops, files);
	}
	else if (ac == 1)
	{
		files = get_filenames("./", '-');
		if (files)
			sort(&files, ops);
		while (files[i])
			print_name(files[i++]);
	}
	deleter(&files, &ops);
	return (0);
}
