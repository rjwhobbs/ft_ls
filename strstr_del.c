/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:48:43 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:48:47 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	strstr_del(char ***del_me)
{
	int i;

	i = 0;
	while ((*del_me)[i])
		free((*del_me)[i++]);
	free(*del_me);
}
