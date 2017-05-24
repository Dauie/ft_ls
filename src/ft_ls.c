/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 20:02:24 by rlutt            ###   ########.fr       */
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
	if ((db->rr_flg && !db->l_flg) || db->dirc > 1)
		ft_putchar('\n');
	if (db->rr_flg == TRUE)
		ls_preprecurs(db);
	closedir(ddir);
	ls_clrtree(&tree);
	return (0);
}

void				ls_traverse(t_rnode *dirs, t_lsnfo *db)
{
	if (dirs->left)
		ls_traverse(dirs->left, db);
	ft_strcpy(db->cdir, dirs->nm);
	ft_printf("%s:\n", dirs->nm);
	list_dir(db, dirs->nm);
	if (dirs->right)
		ls_traverse(dirs->right, db);
}

int					ls_start(t_lsnfo *db)
{
	if (db->a_flg == TRUE && db->aa_flg == TRUE)
		db->aa_flg = FALSE;
	if (db->dirc == 0 && db->fu_flg == FALSE)
	{
		ft_strcpy(db->cdir, ".");
		list_dir(db, ".");
	}
	else if (db->fu_flg == TRUE && db->dirc == 0)
		return (0);
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
	return (0);
}
