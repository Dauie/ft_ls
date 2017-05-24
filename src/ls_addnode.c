/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 18:03:34 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void			ls_addtnoden(t_node **tree, char *name)
{
	t_trinode	tri;

	tri.tt = *tree;
	tri.el = prep_addnode(name);
	if (tri.tt)
	{
		while (tri.tt)
		{
			tri.nt = tri.tt;
			if (ft_strcmp(tri.el->name, tri.tt->name) < 0)
			{
				tri.tt = tri.tt->left;
				if (!tri.tt)
					tri.nt->left = tri.el;
			}
			else
			{
				tri.tt = tri.tt->right;
				if (!tri.tt)
					tri.nt->right = tri.el;
			}
		}
	}
	else
		*tree = tri.el;
}

void			ls_addtnodet(t_node **tree, char *name)
{
	t_trinode	tri;

	tri.tt = *tree;
	tri.el = prep_addnode(name);
	if (tri.tt)
	{
		while (tri.tt)
		{
			tri.nt = tri.tt;
			if (ls_ct(&tri.el->st, &tri.tt->st, tri.el->name, tri.tt->name) < 0)
			{
				tri.tt = tri.tt->left;
				if (!tri.tt)
					tri.nt->left = tri.el;
			}
			else
			{
				tri.tt = tri.tt->right;
				if (!tri.tt)
					tri.nt->right = tri.el;
			}
		}
	}
	else
		*tree = tri.el;
}

void			ls_addrnoden(t_rnode **tree, char *name)
{
	t_trirnode	tri;

	tri.tt = *tree;
	tri.el = prep_addrnode(name);
	if (tri.tt)
	{
		tri.nt = tri.tt;
		while (tri.tt)
		{
			if (tri.tt && ft_strcmp(name, tri.tt->nm) < 0)
			{
				tri.tt = tri.tt->left;
				if (!tri.tt)
					tri.nt->left = tri.el;
			}
			else
			{
				tri.tt = tri.tt->right;
				if (!tri.tt)
					tri.nt->right = tri.el;
			}
		}
	}
	else
		*tree = tri.el;
}

void			ls_addrnodet(t_rnode **tree, char *name)
{
	t_trirnode	tri;

	tri.tt = *tree;
	tri.el = prep_addrnode(name);
	if (tri.tt)
	{
		while (tri.tt)
		{
			tri.nt = tri.tt;
			if (ls_ct(&tri.el->st, &tri.nt->st, tri.el->nm, tri.nt->nm) < 0)
			{
				tri.tt = tri.tt->left;
				if (!tri.tt)
					tri.nt->left = tri.el;
			}
			else
			{
				tri.tt = tri.tt->right;
				if (!tri.tt)
					tri.nt->right = tri.el;
			}
		}
	}
	else
		*tree = tri.el;
}
