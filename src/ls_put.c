/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:05:08 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/17 20:50:33 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

static void		ls_printtree(t_lnode *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtree(tree->left, info);
	if (info->f_long == TRUE)
		ls_putmeta(info, tree->name);
	else
		ft_printf("%s\t", tree->name);
	if (tree->right)
		ls_printtree(tree->right, info);
}

static void		ls_revprinttree(t_lnode *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttree(tree->right, info);
	if (info->f_long == TRUE)
		ls_putmeta(info, tree->name);
	else
		ft_printf("%s  ", tree->name);
	if (tree->left)
		ls_revprinttree(tree->left, info);
}

void			ls_manageput(t_lnode *tree, t_lsnfo *info)
{
	size_t	sz;

	sz = 0;
	if ((info->f_recur == TRUE && ft_strcmp(".", info->cdir) != 0)
		|| info->dircnt--)
		ft_printf("\n%s:\n", info->cdir);
	if (info->f_long == TRUE)
	{
		ls_getblksz(&sz, tree, info);
		if (sz > 0)
			ft_printf("total %lld\n", sz);
	}
	if (info->f_rev == TRUE)
		ls_revprinttree(tree, info);
	else
		ls_printtree(tree, info);
	ft_putchar('\n');
}
