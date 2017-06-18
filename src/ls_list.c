/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:33:09 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/17 18:09:07 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static int			ls_chkdirnam(t_lsnfo *info, char *dirnam)
{
	if (info->f_all == TRUE)
		return (0);
	if (info->f_all == FALSE && info->f_jhidden == FALSE && dirnam[0] == '.')
		return (1);
	if (info->f_jhidden == TRUE && (ft_strcmp(".", dirnam) == 0))
		return (1);
	if (info->f_jhidden == TRUE && (ft_strcmp("..", dirnam) == 0))
		return (1);
	return (0);
}

int					ls_listdir(t_lsnfo *info, char *dir)
{
	t_lnode			*tree;
	struct dirent	*sd;
	DIR				*ddir;

	tree = NULL;
	ddir = NULL;
	if (!(ddir = opendir(dir)))
		return (-1);
	ft_strcpy(info->cdir, dir);
	while ((sd = readdir(ddir)) != NULL)
	{
		if (ls_chkdirnam(info, sd->d_name))
			continue ;
		if (info->f_time == TRUE)
			ls_addnodetime(&tree, sd->d_name, 'd');
		else
			ls_addnodename(&tree, sd->d_name, 'd');
	}
	ls_manageput(tree, info);
	closedir(ddir);
	ls_freetree(&tree);
	if (info->f_recur == TRUE)
		ls_preprecurs(info);
	return (0);
}

int					ls_listfile(t_lsnfo *info, char *name)
{
	t_fmeta			file;

	file.file = ls_getfile(name);
	file.path = ls_getpath(name);
	if (!(file.dir = opendir(file.path)))
		return (-1);
	while ((file.sd = readdir(file.dir)))
	{
		if (ft_strcmp(file.file, file.sd->d_name) == 0)
		{
			if (info->f_long == TRUE)
			{
				ft_strcpy(info->cdir, file.path);
				ls_putmeta(info, file.file);
			}
			else
				ft_putendl(name);
			closedir(file.dir);
			return (1);
		}
	}
	ft_strdel(&file.file);
	ft_strdel(&file.path);
	closedir(file.dir);
	return (0);
}
