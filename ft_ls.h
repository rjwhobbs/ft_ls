#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
int		process_args(char *av[], char *operations[], char **files[]);
int		count_files(char *dirname, int mode);
char	**get_filenames(char *dirname, int mode);
char	**get_filenames_d(char *dirname);
char	**get_dirnames(char parentdir, int mode);
void	sort_lex(char ***names, int number);
void	sort(char ***names);
#endif
