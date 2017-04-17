/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/16 18:29:46 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*void 	manage_lsattrib(t_node *tree)
{
	if (tree->a_flg == TRUE && tree->A_flg == TRUE)
		tree->A_flg = FALSE;
}*/

static void 	ls_initdb(t_lsnfo *db)
{
	db->args = NULL;
	db->dirs = NULL;
	db->l_flg = FALSE;
	db->A_flg = FALSE;
	db->a_flg = FALSE;
	db->R_flg = FALSE;
	db->r_flg = FALSE;
	db->t_flg = FALSE;
}

int 				ls_tickargs(t_lsnfo *db, char *argstr)
{
	int				i;

	i = -1;
	argstr++;
	while (argstr[++i])
	{
		if (ls_isarg(argstr[i]) == 1)
			db->a_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 2)
			db->A_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 3)
			db->r_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 4)
			db->R_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 5)
			db->l_flg = TRUE;
		else if (ls_isarg(argstr[i]) == 6)
			db->t_flg = TRUE;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", argstr[i]);
			ft_printf("usage: ft_ls [-lAaRr] [file ...]");
			return (0);
		}
	}
	return (1);
}

int ls_vrfydir(t_lsnfo *db, char *argstr)
{
	DIR		*chkdir;
	char	**tmp;

	if (!(chkdir = opendir(argstr)))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", argstr);
		return (0);
	}
	closedir(chkdir);
	tmp = db->dirs;
	db->dirs = ft_tbladdl(db->dirs, argstr); //memleak
	ft_puttbl(db->dirs);
	if (tmp)
		ft_tbldel(tmp);
	return (1);
}

int 				ls_anaargs(t_lsnfo *db)
{
	int				i;

	i = -1;
	while (db->args[++i])
	{
		if (*db->args[i] == '-')
		{
			if (!(ls_tickargs(db, db->args[i])))
				return (0);
		}
		else
		{
			if (!(ls_vrfydir(db, db->args[i])))
				return (0);
		}
	}
	ft_tbldel(db->args);
	return (1);
}

int					ls_ftlsreg(void)
{

	t_node			*tree;
	struct dirent	*sd;
	DIR				*ddir;

	if (!(ddir = opendir(".")))
		return (ft_puterror(-4));
	tree = NULL;
	while ((sd = readdir(ddir)) != NULL)
		ls_addtnode(&tree, sd->d_name);
	ls_printtree(tree);
	closedir(ddir);
	return (0);
}

int					main(int ac, char **av)
{
	t_lsnfo			db;

	ls_initdb(&db);
	if (ac > 1)
	{
		db.args = ft_tbldup(&av[1], (ac - 1));
		if (!(ls_anaargs(&db)))
			return (1);
	}
	else
		ls_ftlsreg();
	return (0);
}
