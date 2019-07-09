/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:39:10 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/11 07:35:54 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh_list;
	t_list *begin;

	if (!lst || !(fresh_list = f(lst)))
		return (NULL);
	begin = fresh_list;
	while (lst->next)
	{
		if (!(fresh_list->next = f(lst->next)))
		{
			free(fresh_list);
			return (NULL);
		}
		fresh_list = fresh_list->next;
		lst = lst->next;
	}
	return (begin);
}
