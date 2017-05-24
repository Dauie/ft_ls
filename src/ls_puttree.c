/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_puttree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 18:54:39 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static void		ls_printtree(t_node *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtree(tree->left, info);
	ft_printf("%s\t", tree->name);
	if (tree->right)
		ls_printtree(tree->right, info);
}

static void		ls_revprinttree(t_node *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttree(tree->right, info);
	ft_printf("%s  ", tree->name);
	if (tree->left)
		ls_revprinttree(tree->left, info);
}

static void		ls_printtreel(t_node *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtreel(tree->left, info);
	ls_putmeta(tree, info);
	if (tree->right)
		ls_printtreel(tree->right, info);
}

static void		ls_revprinttreel(t_node *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttreel(tree->right, info);
	ls_putmeta(tree, info);
	if (tree->left)
		ls_revprinttreel(tree->left, info);
}

void			ls_manageput(t_node *tree, t_lsnfo *db)
{
	size_t	sz;

	sz = 0;
	if (db->l_flg == TRUE)
	{
		ls_getblksz(&sz, tree, db);
		ft_printf("total %lld\n", sz);
	}
	if (db->r_flg == TRUE)
	{
		if (db->l_flg == TRUE)
			ls_revprinttreel(tree, db);
		else
			ls_revprinttree(tree, db);
	}
	else
	{
		if (db->l_flg == TRUE)
			ls_printtreel(tree, db);
		else
			ls_printtree(tree, db);
	}
	if ((db->rr_flg && !db->l_flg) || db->dirc > 1)
		ft_putchar('\n');
	db->dirc--;
}
