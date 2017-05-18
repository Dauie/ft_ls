/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/18 15:32:57 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int					list_dir(t_lsnfo *db, char *dir)
{
	t_node			*tree;
	struct dirent	*sd;
	DIR				*ddir;

	if (!(ddir = opendir(dir)))
		return (ft_puterror(-4));
	tree = NULL;
	while ((sd = readdir(ddir)) != NULL)
	{
		if (ls_chkdirnam(db, sd->d_name))
			continue ;
		if (db->t_flg == TRUE)
			ls_addtnodet(&tree, sd->d_name);
		else
			ls_addtnoden(&tree, sd->d_name);
	}
	ls_manageput(tree, db);
	db->dirc--;
	ft_putstr("\n");
	if (db->R_flg == TRUE)
		ls_preprecurs(db);
	closedir(ddir);
	if (tree)
		ls_clrtree(&tree);
	return (0);
}

void				ls_traverse(t_rnode *dirs, t_lsnfo *db)
{
	if (dirs->left)
		ls_traverse(dirs->left, db);
	ft_strcpy(db->cdir, dirs->name);
	ft_printf("%s:\n", dirs->name);
	list_dir(db, dirs->name);
	if (dirs->right)
		ls_traverse(dirs->right, db);
}

int					ls_start(t_lsnfo *db)
{
	if (db->a_flg == TRUE && db->A_flg == TRUE)
		db->A_flg = FALSE;
	if (db->dirc == 0)
	{
		ft_strcpy(db->cdir, ".");
		list_dir(db, ".");
	}
	else
		ls_traverse(db->dirs, db);
	return (1);
}

int					main(int ac, char **av)
{
	t_lsnfo			db;

	ls_initdb(&db);
	if (ac > 1)
	{
		if (!(db.args = ft_tbldup(&av[1], (ac - 1))))
			return (-1);
		if (!(ls_anaargs(&db)))
			return (1);
	}
	ls_start(&db);
	ls_freedb(&db);
	sleep(15);
	return (0);
}
