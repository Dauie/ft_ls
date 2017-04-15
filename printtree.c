/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/13 19:59:14 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	printtree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		printtree(tree->left);
	ft_printf("%s\t", tree->name);
	if (tree->right)
		printtree(tree->right);

}

void 	revprinttree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		revprinttree(tree->left);
	ft_printf("|%s  |", tree->name);
	if (tree->left)
		revprinttree(tree->right);
}
