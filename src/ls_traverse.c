/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_traverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:58:44 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/17 17:33:31 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void				ls_traverse(t_lnode *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_traverse(tree->left, info);
	if (tree->type == 'f')
		ls_listfile(info, tree->name);
	else if (tree->type == 'd')
	{
		ft_strcpy(info->cdir, tree->name);
		ls_listdir(info, tree->name);
	}
	if (info->nl)
	{
		ft_putchar('\n');
		info->nl--;
	}
	if (tree->right)
		ls_traverse(tree->right, info);
}

void				ls_traverserev(t_lnode *tree, t_lsnfo *info)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_traverserev(tree->right, info);
	if (tree->type == 'f')
		ls_listfile(info, tree->name);
	else if (tree->type == 'd')
		ls_listdir(info, tree->name);
	if (info->nl)
	{
		ft_putchar('\n');
		info->nl--;
	}
	if (tree->left)
		ls_traverserev(tree->left, info);
}
