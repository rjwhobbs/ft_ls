#include "ft_ls.h"

void			no_files_ops(char *ops)
{
	char	**strs;
	int		i;

	i = 0;
	strs = get_filenames("./", (ft_strchr(ops, 'a')) ? 'a' : '-');
	if (strs)
		sort(&strs, ops);
	while (strs[i])
		print_name(strs[i++]);
	if (strs)
		strstr_del(&strs);
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
			print_name(*files);
		else
		{
			printdirname(*files);
			if ((strs = get_filenames(*files, '-')))
			{
				sort(&strs, "-");
				while (strs[i])
					print_name(strs[i++]);
				ft_nl();
				strstr_del(&strs);
			}
			else
				print_name(*files);
		}
		files++;
	}
}

void			l_op_no_files(char *ops)
{
	char	**strs;

	strs = get_filenames("./", (ft_strchr(ops, 'a')) ? 'a' : '-');
	sort(&strs, ops);
	print_files_l(strs);
	strstr_del(&strs);
}

void			l_op_files(char *ops, char **fs)
{
	char	**strs;

	sort(&fs, ops);
	while (*fs)
	{
		if (((*fs)[ft_strlen(*fs) - 1]) != '/')
			print_file_l(fs);
		else
		{
			printdirname(*fs);
			if ((strs = get_filenames(*fs, (ft_strchr(ops, 'a')) ? 'a' : '-')))
			{
				sort(&strs, ops);
				print_files_l(strs);
				strstr_del(&strs);
			}
			else
				print_file_l(fs);
		}
		fs++;
	}
}

void			ops_files_no_l(char *ops, char **fs)
{
	char	**strs;
	int		i;

	sort(&fs, ops);
	while (*fs)
	{
		i = 0;
		if (((*fs)[ft_strlen(*fs) - 1]) != '/')
			print_name(*fs);
		else
		{
			printdirname(*fs);
			if ((strs = get_filenames(*fs, (ft_strchr(ops, 'a')) ? 'a' : '-')))
			{
				sort(&strs, ops);
				while (strs[i])
					print_name(strs[i++]);
				ft_nl();
				strstr_del(&strs);
			}
			else
				print_name(*fs);
		}
		fs++;
	}
}
