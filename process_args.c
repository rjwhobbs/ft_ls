/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 07:47:55 by rhobbs            #+#    #+#             */
/*   Updated: 2019/08/19 07:48:00 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	errors(char op, char *free_me)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(op, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-Ralrt] [file ...]", 2);
	free(free_me);
	exit(0);
}

static int	isflag(char c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 't' || c == 'R')
		return (1);
	return (0);
}

static void	process_flags(char **av[], char **op)
{
	char *op_position;

	*op = ft_strnew(5);
	op_position = *op;
	(*av)++;
	while (op_position && **av && ***av == '-' && (**av)[1])
	{
		(**av)++;
		if (***av == '-' && !((**av)[1]))
		{
			(*av)++;
			break ;
		}
		while (**av && isflag(***av))
		{
			if (!ft_strchr(op_position, ***av))
				*(*op)++ = ***av;
			(**av)++;
		}
		if (!***av)
			(*av)++;
		else if (***av)
			errors(***av, op_position);
	}
	*op = op_position;
}

static char	**process_files(char **av[])
{
	int		nfiles;
	char	**files;
	char	**begining_of_files;

	files = NULL;
	nfiles = 0;
	while ((*av)[nfiles])
		nfiles++;
	if (nfiles == 0)
		return (NULL);
	files = (char **)malloc(sizeof(char *) * (nfiles + 1));
	if (files == NULL)
		return (NULL);
	begining_of_files = files;
	while (**av)
	{
		*files = ft_strdup(*(*av)++);
		if (*files++ == NULL)
			return (NULL);
	}
	*files = NULL;
	return (begining_of_files);
}

int			process_args(char *av[], char **operations, char **files[])
{
	process_flags(&av, operations);
	if (!*operations)
		return (-1);
	*files = process_files(&av);
	if (!*files)
		return (-1);
	return (0);
}
