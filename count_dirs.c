/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_dirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:42:29 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:42:36 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	count_dirs(char *dirname, int mode)
{
	DIR				*dir;
	struct dirent	*file;
	int				n;

	n = 0;
	dir = opendir(dirname);
	if (dir == NULL)
		return (-1);
	if (mode == 'a')
	{
		while ((file = readdir(dir)) != NULL)
			if (file->d_type == DT_DIR)
				n++;
	}
	else
		while ((file = readdir(dir)) != NULL)
			if (file->d_type == DT_DIR)
				if (file->d_name[0] != '.')
					n++;
	closedir(dir);
	return (n);
}
