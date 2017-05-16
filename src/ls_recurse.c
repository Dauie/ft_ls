/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:33:41 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/15 23:10:52 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"



t_rnode				*ls_getdirlist(char *dir, t_lsnfo *db)
{
	DIR				*p_dir;
	struct dirent	*sd;
	struct stat		st;
	t_rnode			*r_tree;
	char			*name;

	r_tree = NULL;
	name = NULL;
	if (!(p_dir = opendir(dir)))
		return (NULL);
	while ((sd = readdir(p_dir)) != NULL)
	{
		if (name)
			free(name);
		if (!(name = ls_dirjoin(db->cdir, sd->d_name)))
			return (NULL);
		lstat(name, &st);
		if (S_ISDIR((mode_t)st.st_mode))
		{
			if (sd->d_name[0] == '.' && db->a_flg == FALSE)
				continue;
			if (ft_strcmp(sd->d_name, ".") == 0 ||
					ft_strcmp(sd->d_name, "..") == 0)
				continue;
			ls_addrnoden(&r_tree, name);
		}
	}
	if (name)
		free(name);
	closedir(p_dir);
	return (r_tree);
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
	ls_recurse(db, dirs);
	ls_clrrtree(&dirs);
	return (0);
}
