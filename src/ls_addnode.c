/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/15 15:11:18 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static t_node	*prep_addnode(char *name)
{
	t_node		*elem;
	int			chk;

	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	ls_initnode(elem);
	ft_strcpy(elem->name, name);
	chk = lstat(name, &elem->stat);
	return (elem);
}

static t_rnode	*prep_addrnode(char *name)
{
	t_rnode		*elem;

	if (!(elem = (t_rnode *)ft_memalloc(sizeof(t_rnode))))
		return (NULL);
	ls_initrnode(elem);
	ft_strcpy(elem->name, name);
	return (elem);
}

void			ls_addtnoden(t_node **tree, char *name)
{
	t_trinode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && ft_strcmp(name, tri.ttmp->name) < 0)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*tree = tri.elem;
}

void			ls_addtnodet(t_node **tree, char *name)
{
	t_trinode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.elem->stat.st_mtimespec.tv_nsec >
					tri.ttmp->stat.st_mtimespec.tv_nsec)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*tree = tri.elem;
}

void			ls_addrnoden(t_rnode **tree, char *name)
{
	t_trirnode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addrnode(name);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && ft_strcmp(name, tri.ttmp->name) < 0)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*tree = tri.elem;
}
