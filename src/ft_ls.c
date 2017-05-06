/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/05 20:13:12 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void			manage_lsattrib(t_lsnfo *db)
{
	if (db->a_flg == TRUE && db->A_flg == TRUE)
		db->A_flg = FALSE;
}

int				ls_vrfydir(t_lsnfo *db, char *argstr)
{
	DIR			*chkdir;
	char		**tmp;

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
char				**ls_getdirlist(char *dir)
{
	char			**tmp;
	char			**res;
	DIR				*p_dir;
	struct dirent	*sd;
	struct stat		st;

	res = NULL;
	tmp = NULL;
	if (!(p_dir = opendir(dir)))
		return (NULL);
	while ((sd = readdir(p_dir)) != NULL)
	{	
		lstat(sd->d_name, &st);
		if (S_ISDIR(st.st_mode) && ft_strcmp(sd->d_name, ".") != 0 && ft_strcmp(sd->d_name, "..") != 0)
		{
			tmp = res;
			res = ft_tbladdl(res, sd->d_name);
		}
	}
	return (res);
}

int				ls_recurse(t_lsnfo *db, char *dir)
{
	char		**args;

	args = NULL;
	if (!(args = (char **)ft_memalloc(sizeof(char *) * 3)))
		return (-1);
	args[0] = ft_strdup("ft_db");
	args[1] = ft_strdup(db->type);
	args[2] = ft_strdup(dir);
	main(ft_tbllen(args), args);
	return (0);
}

int				ls_preprecurs(t_lsnfo *db)
{
	char		**dirs;
	size_t		i;
	
	i = -1;
	dirs = NULL;
	if (!(dirs = ls_getdirlist(db->cdir)))
		return (-1);
	while (dirs[++i])
		ls_recurse(db, dirs[i]);
	if (dirs)
		ft_tbldel(dirs);
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
		ls_preprecurs(db);
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
		ft_strcpy(db->cdir, "./");
		list_dir(db, ".");
		}
	else
		while(db->dirs[++i])
		{
			ft_bzero(db->cdir, 1024);
			ft_strcpy(db->cdir, db->dirs[i]);
			ft_printf("%s:\n", db->dirs[i]);
			list_dir(db, db->dirs[i]);
			ft_putstr("\n");
			if (db->dirs[i + 1])
				ft_putstr("\n");
		}
	return (1);
}

int				main(int ac, char **av)
{
	t_lsnfo		db;
	
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
