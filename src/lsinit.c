/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:52 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/18 20:33:59 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void 	ls_initdb(t_lsnfo *db)
{

	db->args = NULL;
	db->dirs = NULL;
	db->dirc = 0;
	db->l_flg = FALSE;
	db->A_flg = FALSE;
	db->a_flg = FALSE;
	db->R_flg = FALSE;
	db->r_flg = FALSE;
	db->t_flg = FALSE;
}

void ls_initnode(t_node *node)
{
	node->name = NULL;
	node->type = 0;
	node->left = NULL;
	node->right = NULL;
	node->data.uid = 0;
	node->data.gid = 0;
	node->data.size = 0;
	node->data.atime = 0;
	node->data.mtime = 0;
	node->data.mntime = 0;
}
