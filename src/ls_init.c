/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:08:52 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 18:54:26 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void	ls_initdb(t_lsnfo *db)
{
	db->args = NULL;
	db->dirs = NULL;
	db->dirc = 0;
	db->fu_flg = FALSE;
	db->l_flg = FALSE;
	db->aa_flg = FALSE;
	db->a_flg = FALSE;
	db->rr_flg = FALSE;
	db->r_flg = FALSE;
	db->t_flg = FALSE;
}

void	ls_freedb(t_lsnfo *db)
{
	if (db->args)
		ft_tbldel(db->args);
	if (db->dirs)
		ls_clrrtree(&db->dirs);
}

void	ls_initnode(t_node *node)
{
	node->left = NULL;
	node->right = NULL;
}

void	ls_initrnode(t_rnode *node)
{
	ft_bzero(node->nm, MXNAMLEN);
	node->right = NULL;
}
