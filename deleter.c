#include "ft_ls.h"

void	deleter(char ***files, char **ops)
{
	if (ops && *ops)
		free(*ops);
	if (files && *files)
		strstr_del(files);
}
