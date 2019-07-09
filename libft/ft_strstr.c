/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:33:03 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/17 13:34:14 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		check;
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (!*needle || !needle)
		return ((char *)haystack);
	while (*haystack)
	{
		check = 1;
		check = ft_strncmp(haystack, needle, nlen);
		if (check == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
