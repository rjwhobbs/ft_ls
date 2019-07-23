#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <time.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <string.h>
# include <errno.h>

int		process_args(char *av[], char *operations[], char **files[]);
int		count_files(char *dirname, int mode);
int		count_dirs(char *dirname, int mode);
char	**get_filenames(char *dirname, int mode);
char	**get_dirnames(char *parentdir, int mode);
void	sort(char ***names, char *args);
void	print_R(char *dir, char *ops);
void	print_files(char **dir);
void	print_files_l(char **files);
void    strstr_del(char ***del_me);
void    print_rec_test(char *dir);
void	print_name(char *file);
void	printdirname(char *dir);

#endif
