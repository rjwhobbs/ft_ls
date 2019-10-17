/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filenames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:43:36 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:43:41 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**filenames_all(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;

	n = count_files(dirname, 'a');
	if (n < 0)
		return (NULL);
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = files;
	dir = opendir(dirname);
	while ((file = readdir(dir)) != NULL)
		*files++ = ft_strjoin(dirname, file->d_name);
	*files = NULL;
	closedir(dir);
	files = temp;
	return (files);
}

static char	**filenames(char *dirname)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**files;
	char			**temp;

	n = count_files(dirname, '-');
	if (n < 0)
		return (NULL);
	files = (char **)malloc(sizeof(char *) * (n + 1));
	temp = files;
	dir = opendir(dirname);
	while ((file = readdir(dir)) != NULL)
		if (file->d_name[0] != '.')
			*files++ = ft_strjoin(dirname, file->d_name);
	*files = NULL;
	closedir(dir);
	files = temp;
	return (files);
}

char		**get_filenames(char *dirname, int mode)
{
	if (mode == 'a')
		return (filenames_all(dirname));
	else
		return (filenames(dirname));
}
