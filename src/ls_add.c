#include "../incl/ft_ls.h"

void			ls_addfile(t_lsnfo *info, char *argstr)
{
	if (info->f_time == TRUE)
		ls_addnodetime(&info->files, argstr, 'f');
	else
		ls_addnodename(&info->files, argstr, 'f');
}

int			ls_adddir(t_lsnfo *info, char *argstr)
{
	if ((access(argstr, R_OK) == -1))
	{
		ft_printf("ft_ls: %s: Permission denied", argstr);
		return (-1);
	}	
	if (info->f_time == TRUE)
		ls_addnodetime(&info->dirs, argstr, 'd');
	else
		ls_addnodename(&info->dirs, argstr, 'd');
	info->dircnt++;
	return (1);
}