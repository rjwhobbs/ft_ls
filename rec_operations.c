#include "ft_ls.h"

void			rec_no_files_no_l(char *ops)
{
	print_rec("./", ops);
}

void			rec_files_no_l(char *ops, char **files)
{
	sort(&files, ops);
	while (*files)
	{
		if (((*files)[ft_strlen(*files) - 1]) != '/')
		{
			print_name(*files++);
			ft_nl();
		}
		else
			print_rec(*files++, ops);
	}
}

void			rec_no_files_l(char *ops)
{
	print_rec("./", ops);
}

void			rec_files_l(char *ops, char **files)
{
	sort(&files, ops);
	while (*files)
	{
		if (((*files)[ft_strlen(*files) - 1]) != '/')
			print_file_l(files);
		else
			print_rec(*files, ops);
		(files)++;
	}
}
