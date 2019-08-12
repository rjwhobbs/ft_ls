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
		{
			print_name(*files);
			ft_nl();
		}
		else
		{
			printdirname(*files);
			if((strs = get_filenames(*files, '-')))
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

void			l_op_files(char *ops, char **files)
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
			if((strs = get_filenames(*files, (ft_strchr(ops, 'a')) ? 'a' : '-')))
			{
				sort(&strs, ops);
				print_files_l(strs);
				strstr_del(&strs);
			}
			else
				print_file_l(files);
		}
		files++;
	}
}

void			ops_files_no_l(char *ops, char **files)
{
	char	**strs;
	int		i;

	sort(&files, ops);
	while (*files)
	{
		i = 0;
		if (((*files)[ft_strlen(*files) - 1]) != '/')
		{
			print_name(*files);
			ft_nl();
		}
		else
		{
			printdirname(*files);
			if((strs = get_filenames(*files, (ft_strchr(ops, 'a')) ? 'a' : '-')))
			{
				sort(&strs, ops);
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
