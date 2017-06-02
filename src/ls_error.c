#include "../incl/ft_ls.h"

int         ls_error(int errcode, char *errstr)
{
    if (errcode == -1)
        ft_printf("ft_ls: error opening %s directory.", errstr);
    else if (errcode == -3)
    {
        ft_printf("ft_ls: illegal option -- %s\n", errstr);
		ft_printf("usage: ft_ls [-lAaRr] [file ...]\n");    
    }
	return (0);
}