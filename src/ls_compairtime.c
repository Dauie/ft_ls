/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_compairtime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:26:44 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/17 16:41:27 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int				ls_compt(struct stat *elem, struct stat *tmp,
				char *ename, char *tname)
{
	int		val;

	val = 0;
	if (elem->st_mtimespec.tv_sec == tmp->st_mtimespec.tv_sec)
	{
		if (elem->st_mtimespec.tv_nsec == tmp->st_mtimespec.tv_nsec)
		{
			if (ft_strcmp(ename, tname) < 0)
				val = -1;
			else
				val = 1;
		}
		else if (elem->st_mtimespec.tv_nsec < tmp->st_mtimespec.tv_nsec)
			val = 1;
		else
			val = -1;
	}
	else if (elem->st_mtime < tmp->st_mtime)
		val = 1;
	else
		val = -1;
	return (val);
}
