#include "ft_ls.h"

static char	**dirnames(char *parentdir)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**dirs;
	char			**temp;

	n = count_dirs(parentdir, '-');
	if (n < 0)
		return (NULL);
	dirs = (char **)malloc(sizeof(char *) * (n + 1));
	temp = dirs;
	dir = opendir(parentdir);
	while ((file = readdir(dir)) != NULL)
		if (file->d_type == DT_DIR)
			if (file->d_name[0] != '.')
				*dirs++ = ft_strjoin(file->d_name, "/");
	*dirs = NULL;
	closedir(dir);
	dirs = temp;
	return (dirs);
}

static char	**dirnames_all(char *parentdir)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**dirs;
	char			**temp;
	
	n = count_dirs(parentdir, 'a');
	if (n < 0)
		return (NULL);
	dirs = (char **)malloc(sizeof(char *) * (n + 1));
	temp = dirs;
	dir = opendir(parentdir);
	while ((file = readdir(dir)) != NULL)
		if (file->d_type == DT_DIR)
			if (!ft_strequ(file->d_name, ".") && !ft_strequ(file->d_name, ".."))
				*dirs++ = ft_strjoin(file->d_name, "/");
	*dirs = NULL;
	closedir(dir);
	dirs = temp;
	return (dirs);
}

char		**get_dirnames(char *parentdir, int mode)
{
	if (mode == 'a')
		return (dirnames_all(parentdir));
	else
		return (dirnames(parentdir));
}
