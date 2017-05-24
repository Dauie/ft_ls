/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fncytree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:18:06 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 16:33:12 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int				ls_cmptime(struct stat *elem, struct stat *tmp, char *ename, char *tname)
{
	int			val;

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

t_node			*prep_addnode(char *name)
{
	t_node		*elem;

	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	ls_initnode(elem);
	ft_strcpy(elem->name, name);
	lstat(name, &elem->stat);
	return (elem);
}

t_rnode			*prep_addrnode(char *name)
{
	t_rnode		*elem;

	if (!(elem = (t_rnode *)ft_memalloc(sizeof(t_rnode))))
		return (NULL);
	ls_initrnode(elem);
	ft_strcpy(elem->name, name);
	lstat(name, &elem->stat);
	return (elem);
}
