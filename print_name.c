/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:46:20 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:46:30 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name(char *file)
{
	char *name_ptr;

	if ((name_ptr = ft_strrchr(file, '/')))
		ft_putendl(name_ptr + 1);
	else
	{
		ft_putendl(file);
		ft_nl();
	}
}
