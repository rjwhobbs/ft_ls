#include "ft_ls.h"

static void match_times(char ***names,  time_t filetimes[])
{
	int i;
	struct stat		filestat;

	i = 0;
	while ((*names)[i])
	{
		stat((*names)[i], &filestat);
		filetimes[i] = filestat.st_mtimespec.tv_sec;
		i++;
	}
}



static void swap_tsec(char **name1, char **name2, time_t *time1, time_t *time2)
{
	char *temp;
	time_t temptime;

	temp = *name1;
	*name1 = *name2;
	*name2 = temp;
	temptime = *time1;
	*time1 = *time2;
	*time2 = temptime;
}

static void swap_tnsec(char **name1, char **name2)
{
	char		*temp;
	struct stat	name1stat;
	struct stat	name2stat;

	stat(*name1, &name1stat);
	stat(*name2, &name2stat);
	if (name1stat.st_mtimespec.tv_nsec < name2stat.st_mtimespec.tv_nsec)
	{
		temp = *name1;
		*name1 = *name2;
		*name2 = temp;
	}
}

void	sort_time(char ***names, int n)
{
	time_t			filetimes[n];
	int				i;
	int				j;
	
	match_times(names, filetimes);
	i = 0;
	j = 0;
	while (j++ < n)
	{
		while (i < n - 1)
		{
			if (filetimes[i] < filetimes[i + 1])
				swap_tsec(&(*names)[i], &(*names)[i + 1], &filetimes[i], &filetimes[i + 1]);
			else if (filetimes[i] == filetimes[i + 1])
				swap_tnsec(&(*names)[i], &(*names)[i + 1]);
			i++;
		}
		i = 0;
	}
}