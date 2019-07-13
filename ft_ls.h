#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
int		process_args(char *av[], char *operations[], char **files[]);
int		count_files(char *dirname);
char	**get_filenames(char *dirname);
char	**get_filenames_d(char *dirname);
void	sort_lex(char ***names, int number);
#endif
