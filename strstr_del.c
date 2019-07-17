#include "ft_ls.h"

void    strstr_del(char ***del_me)
{
    int i;
    i = 0;
    while ((*del_me)[i])
        free((*del_me)[i++]);
    free(*del_me);
    /*
    if (del_me)
    {
        while (**del_me)
        {
            //ft_strdel(*del_me);
            free(**del_me);
            (*del_me)++;
        }
        //free(*del_me);
        //I added this in xcode
        //del_me = NULL;
    }
     */
}
