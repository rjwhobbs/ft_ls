/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:35:16 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/17 14:27:53 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		srclen;
	int			space;
	int			i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	space = dstsize - dstlen - 1;
	i = 0;
	if (space < 0)
		space = 0;
	if (dstlen <= dstsize)
	{
		while (src[i] && i < space)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
		return (dstlen + srclen);
	}
	else
		return (dstsize + srclen);
}
