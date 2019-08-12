#include "ft_ls.h"

void	print_mode(struct stat filestat)
{
	if (S_ISDIR(filestat.st_mode))
		ft_putchar('d');
	else if (S_ISFIFO(filestat.st_mode))
		ft_putchar('p');
	else if (S_ISBLK(filestat.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(filestat.st_mode))
		ft_putchar('c');
	else if (S_ISLNK(filestat.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(filestat.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
	print_perm(filestat);
	ft_putstr(" ");
}

void	print_link(struct stat filestat)
{
	ft_putnbr(filestat.st_nlink);
	ft_putchar('\t');
}

void	print_username(struct stat filestat)
{
	struct passwd	*user;

	user = getpwuid(filestat.st_uid);
	if (user)
	{
		ft_putstr(user->pw_name);
		if (ft_strlen(user->pw_name) > 10)
			ft_putstr(" ");
		else if (ft_strlen(user->pw_name) < 8)
			ft_putstr("\t\t");
		else
			ft_putstr("\t");
	}
	else
		ft_putstr("501 \t\t");
}

void	print_group(struct stat filestat)
{
	struct group *usergroup;

	usergroup = getgrgid(filestat.st_gid);
	if (usergroup == NULL)
	{
		ft_putstr("4000");
		ft_putstr("\t\t");
		return ;
	}
	else
		ft_putstr(usergroup->gr_name);
	if (ft_strlen(usergroup->gr_name) < 4)
		ft_putstr("\t");
	else if (ft_strlen(usergroup->gr_name) < 8)
		ft_putstr("   ");
	else if (ft_strlen(usergroup->gr_name) > 10)
		ft_putstr("\t");
	ft_putstr("\t");
}

void	print_size(struct stat filestat)
{
	if (!(S_ISBLK(filestat.st_mode)) && !(S_ISCHR(filestat.st_mode)))
	{
		ft_putnbr(filestat.st_size);
		if (filestat.st_size > 9999999)
			ft_putchar('\t');
		else
			ft_putstr("\t\t");
	}
}
