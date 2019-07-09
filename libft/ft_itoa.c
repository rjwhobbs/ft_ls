/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:44:41 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/01 15:12:22 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int l;

	l = 0;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	l++;
	return (l);
}

char		*ft_itoa(int n)
{
	char			*s;
	int				sign;
	int				l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n;
	if (n < 0)
		n *= -1;
	l = len(n);
	if (sign < 0)
		l += 1;
	if (!(s = (char*)malloc(sizeof(*s) * (l + 1))))
		return (NULL);
	s[l] = '\0';
	while (l-- >= 0)
	{
		s[l] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign < 0)
		s[0] = '-';
	return (s);
}
