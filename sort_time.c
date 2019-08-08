#include "ft_ls.h"

static void		match_times(char ***names, time_t filetimes[])
{
	int				i;
	struct stat		filestat;

	i = 0;
	while ((*names)[i])
	{
		lstat((*names)[i], &filestat);
		filetimes[i] = filestat.st_mtimespec.tv_sec;
		i++;
	}
}

static void		swap_tsec(char **none, char **ntwo, time_t *tone, time_t *ttwo)
{
	char			*temp;
	time_t			temptime;

	temp = *none;
	*none = *ntwo;
	*ntwo = temp;
	temptime = *tone;
	*tone = *ttwo;
	*ttwo = temptime;
}

static void		swap_tnsec(char **name1, char **name2)
{
	char		*temp;
	struct stat	name1stat;
	struct stat	name2stat;

	lstat(*name1, &name1stat);
	lstat(*name2, &name2stat);
	if (name1stat.st_mtimespec.tv_nsec < name2stat.st_mtimespec.tv_nsec)
	{
		temp = *name1;
		*name1 = *name2;
		*name2 = temp;
	}
}

void			sort_time(char ***names, int n)
{
	time_t			ftm[n];
	int				i;
	int				j;

	match_times(names, ftm);
	i = 0;
	j = 0;
	while (j++ < n)
	{
		while (i < n - 1)
		{
			if (ftm[i] < ftm[i + 1])
				swap_tsec(&(*names)[i], &(*names)[i + 1], &ftm[i], &ftm[i + 1]);
			else if (ftm[i] == ftm[i + 1])
				swap_tnsec(&(*names)[i], &(*names)[i + 1]);
			i++;
		}
		i = 0;
	}
}
