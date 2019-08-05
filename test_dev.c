#include "ft_ls.h"
#include <sys/_types/_dev_t.h>
#include <stdio.h>
//#include <_types.h>
#include <sys/types.h>
//#define major(x)        ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
//#define minor(x)        ((int32_t)((x) & 0xffffff))
//#define makedev(x, y)    ((dev_t)(((x) << 24) | (y)))

int     main(int ac, char *av[])
{
    struct stat		validdir;
	u_int32_t maj;
	int32_t min;
	u_int32_t majd;
	int32_t mind;

	(av)++;
	lstat(*av, &validdir);
	printf("%d\n", validdir.st_dev);
	maj = major(validdir.st_rdev);
	min = minor(validdir.st_rdev);
	majd = major(validdir.st_dev);
	mind = minor(validdir.st_dev);
	//ft_putnbr(major(validdir.st_rdev));
	printf("mind: %d\t min: %d\n", mind, min);
	//ft_nl();
	printf("majd: %d\t maj: %d\n", majd, maj);
	//ft_putnbr(minor(validdir.st_rdev));
	//ft_nl();
	//ft_putnbr(makedev(maj, min));
	//ft_nl();
	return (0);
}