/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sym_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:47:18 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:47:22 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_sym_link(char *filename, struct stat filestat)
{
	char		buf[1024];
	ssize_t		len;

	len = 0;
	if (S_ISLNK(filestat.st_mode))
	{
		len = readlink(filename, buf, 1024);
		buf[len] = 0;
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}
