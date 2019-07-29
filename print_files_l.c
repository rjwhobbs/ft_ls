#include "ft_ls.h"
#include <stdio.h>

static void 	print_error(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(strerror(errno));	
}

int		totalblksize(char **files)
{
	struct stat		file_blk;
	int 			i;
	int				blk_sum;

	i = 0;
	blk_sum = 0;
	while (files[i])
	{
		stat(files[i], &file_blk);
		blk_sum += file_blk.st_blocks;
		i++;
	}
	return (blk_sum);

}

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
    ft_putstr( (filestat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr( (filestat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr( (filestat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr( (filestat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr( (filestat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr( (filestat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr( (filestat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr( (filestat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr( (filestat.st_mode & S_IXOTH) ? "x" : "-");
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
	ft_putstr(user->pw_name);
	ft_putstr("  \t   ");
}

void	print_group(struct stat filestat)
{
	struct group *usergroup;

	usergroup = getgrgid(filestat.st_gid);
	if (usergroup == NULL)
		ft_putstr("4000");
	else
		ft_putstr(usergroup->gr_name);
	ft_putstr("\t");

}

void	print_size(struct stat filestat)
{
	ft_putnbr(filestat.st_size);
	ft_putchar('\t');
}

void	print_time(struct stat filestat)
{
	struct timespec	time;
	char			*str;

	time = filestat.st_mtimespec;
	str = ft_strsub(ctime(&time.tv_sec), 4, 12);
	ft_putstr(str);
	ft_putstr(" ");
	ft_strdel(&str);
}

void	readstat(char *file)
{
	struct stat		filestat;

	//lstat(file, &filestat);
	if((lstat(file, &filestat)) != -1)
	{
		print_mode(filestat);
		print_link(filestat);
		print_username(filestat);
		print_group(filestat);
		print_size(filestat);
		print_time(filestat);
		print_name(file);
		print_sym_link(file, filestat);
		ft_nl();
	}
	else
		print_error(file);
}

void	print_files_l(char **files)
{
	if (*files)
	{
		ft_putstr("total ");
		ft_putnbr(totalblksize(files));
		ft_nl();
	}
	while (*files)
	{
		readstat(*files++);
	}
	ft_nl();
}

