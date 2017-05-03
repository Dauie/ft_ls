/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/03 14:18:11 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "../incl/ft_ls.h"

static t_node *prep_addnode (char *name)
{
	t_node *elem;

	int			chk;

	if (!(elem = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	ls_initnode(elem);
	ft_strcpy(elem->name,name);
	chk = lstat(name, &elem->stat);
	return (elem);
}

void 		ls_addtnoden(t_node **tree, char *name)
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

void 		ls_addtnodet(t_node **tree, char *name)
{
	t_trinode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && tri.elem->stat.st_mtime < tri.ttmp->stat.st_mtime)
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
