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
# include <sys/types.h>

int		process_args(char *av[], char *operations[], char **files[]);
int		count_files(char *dirname, int mode);
int		count_dirs(char *dirname, int mode);
char	**get_filenames(char *dirname, int mode);
char	**get_dirnames(char *parentdir, int mode);
void	sort(char ***names, char *ops);
void	print_rec(char *dir, char *ops);
void	print_files(char **dir);
void	print_files_l(char **files);
void    strstr_del(char ***del_me);
void    print_rec_test(char *dir);
void	print_name(char *file);
void	printdirname(char *dir);
void	sort_time(char ***names, int n);
void    print_sym_link(char *filename, struct stat filestat);
void	print_file_l(char **files);
void	print_perm(struct stat filestat);
void	print_devid(struct stat filestat);
void	print_name_l(char *file);
void	print_mode(struct stat filestat);

#endif
