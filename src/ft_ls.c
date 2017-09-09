/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:48:24 by rlutt             #+#    #+#             */
/*   Updated: 2017/09/09 13:24:46 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"
#include <unistd.h>
int				ls_start(t_lsnfo *info)
{
	if (info->f_all && info->f_jhidden)
		info->f_all = FALSE;
	if (info->files || info->dirs)
	{
		ft_strcpy(info->cdir, ".");
		if (info->files && info->f_rev == FALSE)
			ls_traverse(info->files, info);
		else if (info->files && info->f_rev == TRUE)
			ls_traverserev(info->files, info);
		if (info->dirs && info->f_rev == FALSE)
			ls_traverse(info->dirs, info);
		else if (info->dirs && info->f_rev == TRUE)
			ls_traverserev(info->dirs, info);
	}
	else if (info->f_stop == FALSE)
		ls_listdir(info, ".");
	return (1);
}

int				main(int ac, char **av)
{
	t_lsnfo		info;

	ls_initlsnfo(&info);
	if (ac > 1)
	{
		if (!(info.args = ft_tbldup(&av[1], ac - 1)))
			return (-1);
		if ((ls_parse(&info)) < 0)
			return (-1);
	}
	ls_start(&info);
	ls_freeinfo(&info);
}

int				ls_preprecurs(t_lsnfo *info)
{
	t_lnode		*dirs;

	dirs = NULL;
	if (!(dirs = ls_getdirlist(info->cdir, info)))
		return (-1);
	if (info->f_rev == TRUE)
		ls_revrecurse(info, dirs);
	else
		ls_recurse(info, dirs);
	ls_freetree(&dirs);
	return (0);
}
