/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:19:39 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/13 08:58:03 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*newstring;
	char	*temp;

	len = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(newstring = (char*)malloc(sizeof(*newstring) * (len + 1))))
		return (NULL);
	temp = newstring;
	while (*s1)
	{
		*newstring = *s1++;
		newstring++;
	}
	while (*s2)
	{
		*newstring = *s2++;
		newstring++;
	}
	*newstring = '\0';
	newstring = temp;
	return (newstring);
}
