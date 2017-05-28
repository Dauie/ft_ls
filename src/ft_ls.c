/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/26 20:13:00 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int					ls_lfile(struct dirent *sd, t_lsnfo *db)
{
	if (db->l_flg == TRUE)
	{
		ls_putmetaf(sd->d_name);
	}
	else
	{
		ft_putendl(sd->d_name);
	}
	return (0);
}

int			list_file(char *dir, t_lsnfo *db)
{
	DIR		*dot;
	struct dirent	*sd;

	if (!(dot = opendir(".")))
		return (-1);
	while ((sd = readdir(dot)))
	{
		if (ft_strcmp(dir, sd->d_name) == 0)
		{
			ls_lfile(sd, db);
			return (1);
		}
	}
	ft_printf("could not find %s\n", sd->d_name);
	return (0);
}

int			list_cleanup(t_node *tree, DIR *ddir)
{
	closedir(ddir);
	ls_clrtree(&tree);
	return (0);
}

/*files and folders are now in the tree. If the opendir fails then it sees if it iis a file then print its information accordingly. You will need to put the "file :\n" portion inside of the printtree functions.*/

int			list_dir(t_lsnfo *db, char *dir)
{
	t_node		*tree;
	struct dirent 	*sd;
	DIR		*ddir;
	
	tree = NULL;
	ddir = NULL;
	if (!(ddir = opendir(dir)))
	{
		list_file(dir, db);
		return (0);
	}
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
	if (db->rr_flg == TRUE)
		ls_preprecurs(db);
	list_cleanup(tree, ddir);
	return (0);
}

void			ls_traverse(t_rnode *dirs, t_lsnfo *db)
{
	if (dirs)
	{
		if (dirs->left)
			ls_traverse(dirs->left, db);
		ft_strcpy(db->cdir, dirs->nm);
		list_dir(db, dirs->nm);
		if (dirs->right)
			ls_traverse(dirs->right, db);
	}
}

int			ls_start(t_lsnfo *db)
{
	if (db->a_flg == TRUE && db->aa_flg == TRUE)
		db->aa_flg = FALSE;
	ft_strcpy(db->cdir, ".");
	if (db->dirc == 0 && db->fu_flg == FALSE)
		list_dir(db, db->cdir);
	else if (db->fu_flg == TRUE && db->dirc == 0)
		return (0);
	else
		ls_traverse(db->dirs, db);
	return (1);
}

int			main(int ac, char **av)
{
	t_lsnfo		db;

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
