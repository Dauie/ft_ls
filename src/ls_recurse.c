#include "../incl/ft_ls.h"

int				ls_initlist(t_lsdir *list, char *dir)
{
	list->r_tree = NULL;
	list->name = NULL;
	if (!(list->p_dir = opendir(dir)))
		return (-1);
	else
		return (1);
}

void 			ls_closelist(t_lsdir *list)
{
	ft_strdel(&list->name);
	closedir(list->p_dir);
}

t_lnode				*ls_getdirlist(char *dir, t_lsnfo *info)
{
	t_lsdir		list;

	ls_initlist(&list, dir);
	while ((list.sd = readdir(list.p_dir)) != NULL)
	{
		if (list.name)
			ft_strdel(&list.name);
		if (!(list.name = ls_dirjoin(info->cdir, list.sd->d_name)))
			return (NULL);
		lstat(list.name, &list.st);
		if (S_ISDIR((mode_t)list.st.st_mode))
		{
			if (list.sd->d_name[0] == '.' && info->f_jhidden == FALSE)
				continue;
			if (ft_strcmp(list.sd->d_name, ".") == 0 ||
				ft_strcmp(list.sd->d_name, "..") == 0)
				continue;
			if (info->f_time == TRUE)
				ls_addnodetime(&list.r_tree, list.name, 'd');
			else
				ls_addnodename(&list.r_tree, list.name, 'd');
		}
	}
	ls_closelist(&list);
	return (list.r_tree);
}

int					ls_recurse(t_lsnfo *info, t_lnode *dirs)
{
	char			**args;

	if (dirs->left)
		ls_recurse(info, dirs->left);
	args = NULL;
	if (!(args = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (-1);
	args[0] = ft_strdup("ft_ls");
	args[1] = ft_strdup(info->argflgs);
	args[2] = ft_strdup(dirs->name);
	main(3, args);
	if (args)
		ft_tbldel(args);
	if (dirs->right)
		ls_recurse(info, dirs->right);
	return (0);
}

int					ls_revrecurse(t_lsnfo *info, t_lnode *dirs)
{
	char			**args;

	if (dirs->right)
		ls_recurse(info, dirs->right);
	args = NULL;
	if (!(args = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (-1);
	args[0] = ft_strdup("ft_ls");
	args[1] = ft_strdup(info->argflgs);
	args[2] = ft_strdup(dirs->name);
	main(3, args);
	if (args)
		ft_tbldel(args);
	if (dirs->left)
		ls_recurse(info, dirs->left);
	return (0);
}

int					ls_preprecurs(t_lsnfo *info)
{
	t_lnode			*dirs;

	dirs = NULL;
	if (!(dirs = ls_getdirlist(info->cdir, info)))
		return (-1);
	if (info->f_rev)
		ls_revrecurse(info, dirs);
	else
		ls_recurse(info, dirs);
	ls_freetree(&dirs);
	return (0);
}