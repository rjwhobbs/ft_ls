#include "ft_ls.h"

int main (int ac, char *av[])
{
	char **files;
	char **files2;
	int n;

	if (ac == 2)
	{
		n = count_files(av[1]);
		ft_putnbr(n);
		files = get_filenames(av[1]);
		files2 = files;
		while (*files)
			ft_putendl(*files++);
		sort_lex(&files2, n);
		ft_nl();
		while (*files2)
			ft_putendl(*files2++);
	}
	return (0);
}
