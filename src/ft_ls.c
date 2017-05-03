/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/03 14:35:09 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void 			manage_lsattrib(t_lsnfo *db)
{
	if (db->a_flg == TRUE && db->A_flg == TRUE)
		db->A_flg = FALSE;
}

int 		ls_vrfydir(t_lsnfo *db, char *argstr)
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
	if (!(db->dirs = ft_tbladdl(db->dirs, argstr)))
	 	return (ft_puterror(-3));
	db->dirc++;
	if (tmp)
		ft_tbldel(tmp);
	return (1);
}

/* You need to make sure '.' && '..' are not added to av*/
/* You need to make sure that the current directory is not added to the newest av as well.*/

char		**ls_craftav(t_node *tree, t_lsnfo *db)
{
	char	**res;
	size_t	len;
	size_t	i;

	i = 1;
	len = 0;
	len = ls_diramnt(tree);
	if (!(res = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	if (!(res[0] = ft_strdup("ft_db")))
		return (NULL);
	if (!(res[1] = ft_strdup(db->type)))
		return (NULL);
	ls_dirtotbl(tree, db, res, &i);
	return (res);
}

int			ls_preprecurs(t_lsnfo *db, t_node *tree)
{
	char	**av;
	
	av = NULL;
	av = ls_craftav(tree, db);
	main(ft_tbllen(av), av);
	return (0);
}

int 		ls_anaargs(t_lsnfo *db)
{
	int		i;

	i = -1;
	while (db->args[++i])
	{
		if (*db->args[i] == '-')
		{
			ft_strcpy(db->type, db->args[i]);
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

int 			ls_chkdirnam(t_lsnfo *db, char *dirnam)
{
	if (db->a_flg == TRUE)
		return (0);
	if (db->a_flg == FALSE && db->A_flg == FALSE && dirnam[0] == '.')
		return (1);
	if (db->A_flg == TRUE && (ft_strcmp(".", dirnam) == 0))
		return (1);
	if (db->A_flg == TRUE && (ft_strcmp("..", dirnam) == 0))
		return (1);
	return (0);
}

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
	if (db->r_flg == TRUE)
		ls_revprinttree(tree);
	else
		ls_printtree(tree);
	ft_putchar('\n');
	if (db->R_flg == TRUE)
		ls_preprecurs(db, tree);
	closedir(ddir);
	return (0);
}

int			ls_start(t_lsnfo *db)
{
	size_t	i;
	
	i = -1;
	manage_lsattrib(db);
	if (db->dirc == 0)
	{
		ft_strcpy(db->cdir, ".");
		list_dir(db, ".");
		}
	else
		while(db->dirs[++i])
		{
			ft_bzero(db->cdir, 1024);
			ft_strcpy(db->dirs[i], db->cdir);
			ft_printf("%s:\n", db->dirs[i]);
			list_dir(db, db->dirs[i]);
			ft_putstr("\n");
			if (db->dirs[i + 1])
				ft_putstr("\n");
		}
	return (1);
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
	ls_start(&db);
	return (0);
}
