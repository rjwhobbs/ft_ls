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

void	sort(char ***names)
{
	size_t n;

	n = count_names(*names);
	sort_lex(names, n);
}
