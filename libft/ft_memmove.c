/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:26:41 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/17 14:25:39 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	if (!dst && !src)
		return (NULL);
	i = len;
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (dst > src)
		while (i-- > 0)
			pdst[i] = psrc[i];
	else
		dst = ft_memcpy(dst, src, len);
	return ((void *)dst);
}
