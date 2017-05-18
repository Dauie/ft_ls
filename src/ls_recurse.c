/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:33:41 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/18 15:35:34 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int					ls_initnfo(t_lsdir *nfo, char *dir)
{
	nfo->r_tree = NULL;
	nfo->name = NULL;
	if (!(nfo->p_dir = opendir(dir)))
		return (-1);
	else
		return (1);
}

void				ls_closenfo(t_lsdir *nfo)
{
	ft_strdel(&nfo->name);
	closedir(nfo->p_dir);
}

t_rnode				*ls_getdirlist(char *dir, t_lsnfo *db)
{
	t_lsdir		nfo;

	ls_initnfo(&nfo, dir);
	while ((nfo.sd = readdir(nfo.p_dir)) != NULL)
	{
		if (nfo.name)
			ft_strdel(&nfo.name);
		if (!(nfo.name = ls_dirjoin(db->cdir, nfo.sd->d_name)))
			return (NULL);
		lstat(nfo.name, &nfo.st);
		if (S_ISDIR((mode_t)nfo.st.st_mode))
		{
			if (nfo.sd->d_name[0] == '.' && db->a_flg == FALSE)
				continue;
			if (ft_strcmp(nfo.sd->d_name, ".") == 0 ||
				ft_strcmp(nfo.sd->d_name, "..") == 0)
				continue;
			if (db->t_flg == TRUE)
				ls_addrnodet(&nfo.r_tree, nfo.name);
			else
				ls_addrnoden(&nfo.r_tree, nfo.name);
		}
	}
	ls_closenfo(&nfo);
	return (nfo.r_tree);
}

int					ls_recurse(t_lsnfo *db, t_rnode *dirs)
{
	char			**args;

	if (dirs->left)
		ls_recurse(db, dirs->left);
	args = NULL;
	if (!(args = (char **)ft_memalloc(sizeof(char *) * 4)))
		return (-1);
	args[0] = ft_strdup("ft_ls");
	args[1] = ft_strdup(db->type);
	args[2] = ft_strdup(dirs->name);
	main(3, args);
	if (args)
		ft_tbldel(args);
	if (dirs->right)
		ls_recurse(db, dirs->right);
	return (0);
}

int					ls_preprecurs(t_lsnfo *db)
{
	t_rnode			*dirs;

	dirs = NULL;
	if (!(dirs = ls_getdirlist(db->cdir, db)))
		return (-1);
	db->nl = (ls_getmbramt(dirs) - 1);
	ls_recurse(db, dirs);
	ls_clrrtree(&dirs);
	return (0);
}
