/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:47:05 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:47:09 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	sort_print(char ***files, char ***dirs, char *dir, char *ops)
{
	if (*dirs)
		sort(dirs, ops);
	if (files && *files)
		sort(files, ops);
	printdirname(dir);
	if (ft_strchr(ops, 'l'))
	{
		if (*files)
			print_files_l(*files);
		else
			print_file_l(&dir);
	}
	else
		print_files(*files);
}

void		print_rec(char *dir, char *ops)
{
	char **files;
	char **dirs;
	char *tempdir;
	char **temp2;

	files = get_filenames(dir, (ft_strchr(ops, 'a')) ? 'a' : '-');
	dirs = get_dirnames(dir, (ft_strchr(ops, 'a')) ? 'a' : '-');
	temp2 = dirs;
	sort_print(&files, &dirs, dir, ops);
	if (dirs)
		while (*dirs)
		{
			tempdir = ft_strjoin(dir, *dirs++);
			print_rec(tempdir, ops);
			free(tempdir);
		}
	if (temp2)
		strstr_del(&temp2);
	if (files)
		strstr_del(&files);
}
