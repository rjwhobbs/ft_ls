/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdirname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:47:44 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:47:49 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printdirname(char *dir)
{
	char *last_slash;
	char *temp;

	temp = dir;
	if ((last_slash = ft_strrchr(dir, '/')))
		if (!(ft_strequ(dir, "./")))
		{
			while (temp < last_slash)
				ft_putchar(*temp++);
			ft_putendl(":");
		}
}
