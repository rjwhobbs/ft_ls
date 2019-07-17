#include <dirent.h>
#include "ft_ls.h"

static char	**error(char *dir)
{
	ft_putstr_fd(dir, 2);
	ft_putendl_fd("is not a valid directory", 2);
	return (NULL);
}
static char	**dirnames(char *parentdir)
{
	DIR				*dir;
	int				n;
	struct dirent	*file;
	char			**dirs;
	char			**temp;

	n = count_files(parentdir, '-');
	dirs = (char **)malloc(sizeof(char *) * (n + 1));
	temp = dirs;
	if ((dir = opendir(parentdir)) == NULL)
		return (error(parentdir));
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
	dirs = (char **)malloc(sizeof(char *) * (n + 1));
	temp = dirs;
	if ((dir = opendir(parentdir)) == NULL)
		return (error(parentdir));
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
