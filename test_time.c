#include "ft_ls.h"
#include <time.h>
#include <sys/stat.h>

int	main(void)
{
	struct stat filestat;
	struct timespec T;

	int i = stat("Makefile", &filestat);

	T = filestat.st_ctimespec;

	ft_putendl(ctime(&T.tv_sec));


	return (0);
}
