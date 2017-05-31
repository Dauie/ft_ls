
#include "../incl/ft_ls.h"

static int					ls_chkdirnam(t_lsnfo *info, char *dirnam)
{
	if (info->f_all == TRUE)
		return (0);
	if (info->f_all == FALSE && info->f_jhidden == FALSE && dirnam[0] == '.')
		return (1);
	if (info->f_jhidden == TRUE && (ft_strcmp(".", dirnam) == 0))
		return (1);
	if (info->f_jhidden == TRUE && (ft_strcmp("..", dirnam) == 0))
		return (1);
	return (0);
}

int					ls_listdir(t_lsnfo *info, char *dir)
{
	t_lnode			*tree;
	struct dirent	*sd;
	DIR				*ddir;

	tree = NULL;
	ddir = NULL;
	if (!(ddir = opendir(dir)))
		return (-1);
	ft_strcpy(info->cdir, dir);
	while ((sd = readdir(ddir)) != NULL)
	{
		if (ls_chkdirnam(info, sd->d_name))
			continue ;
		if (info->f_time == TRUE)
			ls_addnodetime(&tree, sd->d_name, 'f');
		else
			ls_addnodename(&tree, sd->d_name, 'f');
	}
	ls_manageput(tree, info);
	if (info->f_recur == TRUE)
		ls_preprecurs(info);
	return (0);
}

int					ls_listfile(t_lsnfo *info, char *name)
{
	DIR				*dir;
	struct dirent	*sd;
	char			*path;
	char			*file;

	file = ls_getfile(name);
	path = ls_getpath(name);
	if (!(dir = opendir(path)))
		return (-1);
	while ((sd = readdir(dir)))
	{
		if (ft_strcmp(file, sd->d_name) == 0)
		{
			if (info->f_long == TRUE)
			{
				ft_strcpy(info->cdir, path);
				ls_putmeta(info, file);
			}
			else
				ft_putendl(name);
			return (1);
		}
	}
	ft_printf("could not find %s\n", sd->d_name);
	return (0);
}
