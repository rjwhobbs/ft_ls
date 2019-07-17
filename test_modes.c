#include "ft_ls.h"

int main(void)
{
	char **files = ft_strsplit("Makefile main.c print_R.c sort.c ft_ls libft f", ' ');
	print_files_l(files);
	return (0);
}
