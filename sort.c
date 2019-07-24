#include "ft_ls.h"

size_t	count_names(char **names)
{
	size_t i;

	i = 0;
	while (names[i])
		i++;
	return (i);
}


static void	sort_lex(char ***names, int n)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j++ < n)
	{
		while (i < n - 1)
		{
			if (ft_strcmp((*names)[i], (*names)[i + 1]) > 0)
			{
				temp = (*names)[i];
				(*names)[i] = (*names)[i + 1];
				(*names)[i + 1] = temp;
			}
			i++;
		}
		i = 0;
	}
}

static void	sort_time(char ***names, int n)
{
	char			*temp;
	struct timespec time;
	struct stat		filestat;
	time_t			filetimes[n];
	time_t			temptime;
	int				i;
	int				j;
	
	i = 0;
	while ((*names)[i])
	{
		stat((*names)[i], &filestat);
		time = filestat.st_mtimespec;
		filetimes[i] = time.tv_sec;
		i++;
	}
	i = 0;
	j = 0;
	while (j++ < n)
	{
		while (i < n - 1)
		{
			if (filetimes[i] < filetimes[i + 1])
			{
				temp = (*names)[i];
				(*names)[i] = (*names)[i + 1];
				(*names)[i + 1] = temp;
				temptime = filetimes[i];
				filetimes[i] = filetimes[i + 1];
				filetimes[i + 1] = temptime;
			}
			i++;
		}
		i = 0;
	}
}
void	sort_rev(char ***names, int n)
{
	char	*temp;
	int		i;

	i = 0;
	n--;
	while (i < n)
	{
		temp = (*names)[i];
		(*names)[i] = (*names)[n];
		(*names)[n] = temp;
		i++;
		n--;
	}
}
void	sort(char ***names, char *ops)
{
	size_t n;

	n = count_names(*names);
	sort_lex(names, n);
	if (ops)
	{
		if (ft_strchr(ops, 't'))
			sort_time(names, n);
		if (ft_strchr(ops, 'r'))
			sort_rev(names, n);
	}
}
