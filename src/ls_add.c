#include "../incl/ft_ls.h"

void			ls_addfile(t_lsnfo *info, char *argstr)
{
	if (info->f_time == TRUE)
		ls_addnodetime(&info->files, argstr, 'f');
	else
		ls_addnodename(&info->files, argstr, 'f');
}

void			ls_adddir(t_lsnfo *info, char *argstr)
{
	if (info->f_time == TRUE)
		ls_addnodetime(&info->dirs, argstr, 'd');
	else
		ls_addnodename(&info->dirs, argstr, 'd');
	info->dircnt++;
}