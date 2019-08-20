/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:46:38 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:46:44 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name_l(char *file)
{
	char *name_ptr;

	if ((name_ptr = ft_strrchr(file, '/')))
		ft_putstr(name_ptr + 1);
	else
		ft_putstr(file);
}
