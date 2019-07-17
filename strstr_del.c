#include "ft_ls.h"

void    strstr_del(char ***del_me)
{
    if (del_me)
    {
        while (**del_me)
        {
            ft_strdel(*del_me);
            (*del_me)++;
        }
        //free(*del_me);
        *del_me = NULL;
    }
}