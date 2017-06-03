#include "../incl/ft_ls.h"

int			ls_start(t_lsnfo *info)
{
	if (info->f_all && info->f_jhidden)
		info->f_all = FALSE;
	if (info->files || info->dirs)
	{
		ft_strcpy(info->cdir, ".");
		if (info->files && info->f_rev == FALSE)
			ls_traverse(info->files, info);
		else if (info->files && info->f_rev == TRUE)
			ls_traverserev(info->files, info);
		if (info->dirs && info->f_rev == FALSE)
			ls_traverse(info->dirs, info);
		else if (info->dirs && info->f_rev == TRUE)
			ls_traverserev(info->dirs, info);
	}
	else if (info->f_stop == FALSE)
		ls_listdir(info, ".");
	return (1);
}

int         main(int ac, char **av)
{
    t_lsnfo info;

    ls_initlsnfo(&info);
    if (ac > 1)
    {
        if (!(info.args = ft_tbldup(&av[1], ac - 1)))
            return (-1);
        if ((ls_parse(&info)) < 0)
            return (-1);
    }
	ls_start(&info);
	ls_freeinfo(&info);
}