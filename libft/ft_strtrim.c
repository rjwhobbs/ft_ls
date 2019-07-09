/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:23:06 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/20 15:23:17 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t len;
	size_t start;
	size_t end;

	if (s == NULL)
		return (NULL);
	len = 0;
	start = 0;
	end = (ft_strlen(s) - 1);
	if (end > ft_strlen(s))
		return (ft_strnew(0));
	while ((s[start] >= '\t' && s[start] <= '\r') || s[start] == ' ')
		start++;
	if ((start - 1) == end)
		return (ft_strnew(0));
	while ((s[end] >= '\t' && s[end] <= '\r') || s[end] == ' ')
		end--;
	len = (end - start + 1);
	return ((ft_strsub(s, start, len)));
}
