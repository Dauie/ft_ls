/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 16:39:39 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

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
			if (ft_strcmp(tri.elem->name, tri.ttmp->name) < 0)
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
// STILL FIXKING TIME. FIGURE IT OUT!

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
			if (ls_cmptime(&tri.elem->stat, &tri.ttmp->stat,
						tri.elem->name, tri.ttmp->name) < 0)
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
		tri.ntmp = tri.ttmp;
		while (tri.ttmp)
		{
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

void			ls_addrnodet(t_rnode **tree, char *name)
{
	t_trirnode	tri;

	tri.ttmp = *tree;
	tri.elem = prep_addrnode(name);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (ls_cmptime(&tri.elem->stat, &tri.ntmp->stat,
						tri.elem->name, tri.ntmp->name) < 0)
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
