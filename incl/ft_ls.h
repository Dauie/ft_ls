/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:10 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/23 18:52:47 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/incl/bool.h"
# include "../libft/incl/char.h"
# include "../libft/incl/cnvrsn.h"
# include "../libft/incl/gnl.h"
# include "../libft/incl/lst.h"
# include "../libft/incl/mem.h"
# include "../libft/incl/num.h"
# include "../libft/incl/put.h"
# include "../libft/incl/printf.h"
# include <dirent.h>
# include <time.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# define MXDIRLEN 1024
# define MXNAMLEN 256
# define MXTYPLEN 42

typedef struct		s_cduo
{
	char *uno;
	char *dos;
}					t_cduo;

typedef struct		s_rnode
{
	char			nm[MXNAMLEN];
	struct stat		st;
	struct s_rnode	*left;
	struct s_rnode	*right;
}					t_rnode;

typedef struct		s_trirnode
{
	t_rnode			*el;
	t_rnode			*nt;
	t_rnode			*tt;
}					t_trirnode;

typedef struct		s_node
{
	char			cdir[MXNAMLEN];
	char			name[MXNAMLEN];
	struct stat		st;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_trinode
{
	t_node			*el;
	t_node			*nt;
	t_node			*tt;
}					t_trinode;

typedef struct		s_lsdir
{
	DIR				*p_dir;
	struct dirent	*sd;
	struct stat		st;
	t_rnode			*r_tree;
	char			*name;
}					t_lsdir;

typedef struct		s_lsnfo
{
	char			**args;
	t_rnode			*dirs;
	size_t			dirc;
	char			type[MXTYPLEN];
	char			cdir[MXNAMLEN];
	size_t			nl;
	t_blean			fu_flg;
	t_blean			l_flg;
	t_blean			aa_flg;
	t_blean			a_flg;
	t_blean			rr_flg;
	t_blean			r_flg;
	t_blean			t_flg;
}					t_lsnfo;

int					main(int ac, char **av);
int					list_dir(t_lsnfo *db, char *dir);
int					ls_start(t_lsnfo *db);
void				ls_addtnoden(t_node **tree, char *name);
void				ls_addtnodet(t_node **tree, char *name);
void				ls_addrnoden(t_rnode **tree, char *name);
void				ls_addrnodet(t_rnode **tree, char *name);
void				ls_clrtree(t_node **tree);
void				ls_clrrtree(t_rnode **tree);
char				*ls_dirjoin(const char *s1, const char *s2);
void				ls_initdb(t_lsnfo *db);
void				ls_freedb(t_lsnfo *db);
void				ls_initnode(t_node *node);
void				ls_initrnode(t_rnode *node);
void				ls_getblksz(size_t *sz, t_node *tree, t_lsnfo *info);
void				ls_putmeta(t_node *node, t_lsnfo *info);
void				ls_manageput(t_node *tree, t_lsnfo *db);
t_rnode				*ls_getdirlist(char *dir, t_lsnfo *db);
int					ls_recurse(t_lsnfo *db, t_rnode *dirs);
int					ls_preprecurs(t_lsnfo *db);
int					ls_treesearch(t_node *tree, char *name);
unsigned int		ls_diramnt(t_node *tree);
unsigned int		ls_getmbramt(t_rnode *tree);
void				ls_dirtree(t_node *tree, t_lsnfo *db, char **av, size_t i);
int					ls_ct(struct stat *e, struct stat *t, char *el, char *tm);
t_node				*prep_addnode(char *name);
t_rnode				*prep_addrnode(char *name);
int					ls_chkdirnam(t_lsnfo *db, char *dirnam);
int					ls_anaargs(t_lsnfo *db);
#endif
