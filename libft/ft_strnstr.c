/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 06:54:50 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/17 13:33:15 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	int			check;
	size_t		nlen;
	int			i;

	nlen = ft_strlen(ndl);
	i = 0;
	if (!ndl)
		return ((char *)hay);
	while ((hay[i]) && nlen <= (len - i))
	{
		check = 1;
		check = ft_strncmp(&hay[i], ndl, nlen);
		if (check == 0)
			return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}
