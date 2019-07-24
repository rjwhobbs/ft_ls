#include "ft_ls.h"
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

void putlong_n(char *s)
{
	unsigned long long int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);

}

int	main(void)
{
	struct stat 	filestat;
	struct timespec T;
	time_t			time;

	int i = stat("Makefile", &filestat);

	time = filestat.st_ctimespec.tv_nsec;

	printf("%ld", time);
	//ft_putendl(ctime(&time));


	return (0);
}
