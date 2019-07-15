#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
int		process_args(char *av[], char *operations[], char **files[]);
int		count_files(char *dirname, int mode);
int		count_dirs(char *dirname, int mode);
char	**get_filenames(char *dirname, int mode);
char	**get_filenames_d(char *dirname);
char	**get_dirnames(char *parentdir, int mode);
void	sort(char ***names);
void	print_R(char *dir);
void	print_files(char **dir);
#endif
