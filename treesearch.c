/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treesearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/12 19:08:45 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		treesearch(t_node *tree, unsigned int key)
{
	t_node	*tmp;

	tmp = tree;
	while (tmp)
	{
		if (key == tmp->key)
			return (1);
		if (key > tmp->key)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (0);
}
