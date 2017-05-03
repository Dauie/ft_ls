/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:52 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/03 14:18:34 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void 	ls_initdb(t_lsnfo *db)
{
	db->args = NULL;
	db->dirs = NULL;
	db->dirc = 0;
	ft_bzero(db->type, 12);
	ft_bzero(db->cdir, 1024);
	db->l_flg = FALSE;
	db->A_flg = FALSE;
	db->a_flg = FALSE;
	db->R_flg = FALSE;
	db->r_flg = FALSE;
	db->t_flg = FALSE;
}

void ls_initnode(t_node *node)
{
	ft_bzero(node->name, 1024);
	ft_bzero(node->cdir, 1024);
	node->left = NULL;
	node->right = NULL;
}
