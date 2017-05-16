/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lmeta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:29:07 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/15 22:46:48 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void				ls_getblksz(size_t *sz, t_node *tree, t_lsnfo *info)
{
	struct stat		st;
	char			*name;

	if (!tree)
		return ;
	if (tree->left)
		ls_getblksz(sz, tree->left, info);
	if (tree->right)
		ls_getblksz(sz, tree->right, info);
	if (!(name = ls_dirjoin(info->cdir, tree->name)))
		return ;
	lstat(name, &st);
	*sz += st.st_blocks;
	ft_strdel(&name);
}

void				ls_putpermtype(struct stat *st)
{
	if (S_ISREG(st->st_mode))
		ft_putchar('-');
	else if (S_ISDIR(st->st_mode))
		ft_putchar('d');
	else if (S_ISLNK(st->st_mode))
		ft_putchar('l');
	else if (S_ISBLK(st->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(st->st_mode))
		ft_putchar('c');
	else if (S_ISSOCK(st->st_mode))
		ft_putchar('s');
	else if (S_ISFIFO(st->st_mode))
		ft_putchar('p');
	else
		ft_putchar('-');
}

void				ls_putperm(struct stat *st)
{
	ls_putpermtype(st);
	ft_putchar((st->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((st->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((st->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((st->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((st->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((st->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((st->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((st->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((st->st_mode & S_IXOTH) ? 'r' : '-');
	ft_putchar(' ');
}

void				ls_putmeta(t_node *node, t_lsnfo *info)
{
	struct stat		st;
	struct passwd	*pw;
	struct group	*gp;
	t_cduo			strs;
	char			time[MXNAMLEN];
	
	if (!(strs.uno = ls_dirjoin(info->cdir, node->name)))
		return ;
	lstat(strs.uno, &st);
	strs.dos = ctime(&st.st_mtime);
	ft_strcpy(time, &strs.dos[4]);
	ls_putperm(&st);
	pw = getpwuid(st.st_uid);
	gp = getgrgid(st.st_gid);
	ft_printf("%3lld % 6s %9s % 7lld  %.12s  %s\n", st.st_nlink, pw->pw_name,
			gp->gr_name, st.st_size, time, node->name);
	free(strs.uno);
}
