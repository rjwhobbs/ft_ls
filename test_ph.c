#include "ft_ls.h"

int main(int ac, char *av[])
{
	int x;

	x = ft_atoi(av[1]);
	ft_print_hex(x);
	ft_nl();
	return (0);
}