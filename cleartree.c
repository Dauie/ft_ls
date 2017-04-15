/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleartree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:26 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/13 16:37:09 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void cleartree(t_node **tree)
{
	t_node		*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
		cleartree(&tmp->left);
	if (tmp->right)
		cleartree(&tmp->right);
	free(tmp);
	tree = NULL;
}
