/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:45:43 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:45:48 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_error(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
	errno = 0;
}

static int		totalblksize(char **files)
{
	struct stat		file_blk;
	int				i;
	int				blk_sum;

	i = 0;
	blk_sum = 0;
	while (files[i])
	{
		if (stat(files[i], &file_blk) != -1)
		{
			blk_sum += file_blk.st_blocks;
			i++;
		}
		else
			i++;
	}
	return (blk_sum);
}

void			readstat(char *file)
{
	struct stat		filestat;

	if ((lstat(file, &filestat)) != -1)
	{
		print_mode(filestat);
		print_link(filestat);
		print_username(filestat);
		print_group(filestat);
		print_devid(filestat);
		print_size(filestat);
		print_time(filestat);
		print_name_l(file);
		print_sym_link(file, filestat);
		ft_nl();
	}
	else
		print_error(file);
}

void			print_files_l(char **files)
{
	if (*files)
	{
		ft_putstr("total ");
		ft_putnbr(totalblksize(files));
		ft_nl();
	}
	while (*files)
		readstat(*files++);
	ft_nl();
}
