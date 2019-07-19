#include "ft_ls.h"

void    strstr_del(char ***del_me)
{
    int i;
    
    i = 0;
    while ((*del_me)[i])
        free((*del_me)[i++]);
    free(*del_me);

}
