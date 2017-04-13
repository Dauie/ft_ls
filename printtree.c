/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/12 19:08:35 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	printtree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		printtree(tree->left);
	ft_printf("key: %d", tree->key);
	if (tree->right)
		printtree(tree->right);
}

void 	revprinttree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		revprinttree(tree->left);
	ft_printf("key: %d", tree->key);
	if (tree->left)
		revprinttree(tree->right);
}
