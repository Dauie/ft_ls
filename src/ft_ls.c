/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:46:56 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/12 12:56:57 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void				manage_lsattrib(t_lsnfo *db)
{
	if (db->a_flg == TRUE && db->A_flg == TRUE)
		db->A_flg = FALSE;
}


// allocation - being free, but verify
int					ls_vrfydir(t_lsnfo *db, char *argstr)
{
	DIR				*chkdir;
	char			**tmp;

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

t_rnode				*ls_getdirlist(char *dir, t_lsnfo *db)
{
	DIR				*p_dir;
	struct dirent	*sd;
	struct stat		st;
	t_rnode			*r_tree;
	char			*name;

	r_tree = NULL;
	if (!(p_dir = opendir(dir)))
		return (NULL);
	while ((sd = readdir(p_dir)) != NULL)
	{
		name = ls_dirjoin(db->cdir, sd->d_name);
		lstat(name, &st);
		if (S_ISDIR((mode_t)st.st_mode))
		{
			if (sd->d_name[0] == '.' && db->a_flg == FALSE)
				continue;
			if (ft_strcmp(sd->d_name, ".") == 0 || ft_strcmp(sd->d_name, "..") == 0)
				continue;
					ls_addrnoden(&r_tree, ls_dirjoin(db->cdir, sd->d_name));
		}
		ft_strdel(&name);
	}
	return (r_tree);
}


//allocation - had trouble freeing due to it being a recursive function.
int					ls_recurse(t_lsnfo *db, t_rnode *dirs)
{
	char			**args;

	if(dirs->left)
		ls_recurse(db, dirs->left);
	args = NULL;
	if (!(args = (char **)ft_memalloc(sizeof(char *) * 3)))
		return (-1);
	args[0] = ft_strdup("ft_ls");
	args[1] = ft_strdup(db->type);
	args[2] = ft_strdup(dirs->name);
	main(3, args);
	if (dirs->right)
		ls_recurse(db,dirs->right);
	return (0);
}


//allocation - make sure tree is being freed 
int					ls_preprecurs(t_lsnfo *db)
{
	t_rnode			*dirs;
	size_t			i;

	i = -1;
	dirs = NULL;
	if (!(dirs = ls_getdirlist(db->cdir, db)))
		return (-1);
	ls_recurse(db, dirs);
	//ls_clrrtree(dirs);
	return (0);
}

int					ls_anaargs(t_lsnfo *db)
{
	int				i;

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
	return (1);
}

int					ls_chkdirnam(t_lsnfo *db, char *dirnam)
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

void				manage_print(t_node *tree, t_lsnfo *db)
{
	if (db->r_flg == TRUE)
	{
		if (db->l_flg == TRUE)
			ls_revprinttreel(tree, db);
		else
			ls_revprinttree(tree);
	}
	else
	{
		if (db->l_flg == TRUE)
			ls_printtreel(tree, db);
		else
			ls_printtree(tree);
	}
	ft_putstr("\n\n");
}

// allocation -- need to free main tree
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
	manage_print(tree, db);
	if (db->R_flg == TRUE)
		ls_preprecurs(db);
	closedir(ddir);
	//ls_clrtree(tree);
	return (0);
}

int					ls_start(t_lsnfo *db)
{
	size_t			i;

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
			ft_bzero(db->cdir, MXNAMLEN);
			ft_strcpy(db->cdir, db->dirs[i]);
			ft_printf("%s:\n", db->dirs[i]);
			list_dir(db, db->dirs[i]);
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
	ls_freedb(&db);
	return (0);
}
