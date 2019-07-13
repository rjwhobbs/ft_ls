#include "ft_ls.h"

void	sort_lex(char ***names, int n)
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
