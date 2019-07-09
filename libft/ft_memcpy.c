/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:15:29 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/17 13:22:15 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (i < n)
		pdst[i++] = *psrc++;
	return (dst);
}
