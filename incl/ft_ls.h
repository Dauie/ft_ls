/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:10 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/26 20:12:29 by rlutt            ###   ########.fr       */
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

# define MXDIRLEN 512
# define MXNAMLEN 256
# define MXTYPLEN 42

typedef struct		s_cduo
{
	char			*uno;
	char			*dos;
}					t_cduo;

typedef struct		s_meta
{
	struct stat		st;
	struct passwd	*pw;
	struct group	*gp;
	char			*date;
	char			time[MXNAMLEN];
	char			*fullpath;
}					t_meta;

typedef struct 		s_lnode
{	
	char			name[MXNAMLEN];
	char			type;
	struct stat		st;
	struct s_lnode 	*left;
	struct s_lnode	*right;
}					t_lnode;

typedef struct		s_lsdir
{
	DIR				*p_dir;
	struct dirent	*sd;
	struct stat		st;
	t_lnode			*r_tree;
	char			*name;
}					t_lsdir;

typedef struct 		s_trinode
{
	t_lnode			*el;
	t_lnode			*tt;
	t_lnode			*nt;
}					t_trinode;

typedef struct		s_lsnfo
{
	char			*p_args;
	char			argflgs[MXTYPLEN];
	char			**args;
	char 			cdir[MXDIRLEN];
	int				nl;
	int 			dircnt;
	t_lnode			*files;
	t_lnode			*dirs;
	t_blean			f_stop;
	t_blean			f_long;
	t_blean			f_all;
	t_blean			f_jhidden;
	t_blean			f_rev;
	t_blean			f_time;
	t_blean			f_recur;
}					t_lsnfo;

int					main(int ac, char **av);
int					ls_preprecurs(t_lsnfo *info);
void				ls_freetree(t_lnode **tree);
char				*ls_getpath(char *argstr);
char				*ls_getfile(char *argstr);
void				ls_addfile(t_lsnfo *info, char *argstr);
void				ls_adddir(t_lsnfo *info, char *argstr);
void				ls_initlsnfo(t_lsnfo *info);
char				*ls_dirjoin(const char *stra, const char *strb);
int         		ls_parse(t_lsnfo *info);
int         		ls_error(int errcode, char *errstr);
void				ls_initnode(t_lnode *node);
void				ls_traverse(t_lnode *tree, t_lsnfo *info);
void				ls_traverserev(t_lnode *tree, t_lsnfo *info);
int					ls_listdir(t_lsnfo *info, char *dir);
int					ls_listfile(t_lsnfo *info, char *name);
void				ls_manageput(t_lnode *tree, t_lsnfo *info);
void				ls_freeinfo(t_lsnfo *info);
void				ls_addnodename(t_lnode **tree, char *name, char type);
void				ls_addnodetime(t_lnode **tree, char *name, char type);
int					ls_compt(struct stat *elem, struct stat *tmp,char *ename, char *tname);
void				ls_putmeta(t_lsnfo *info, char *name);
void				ls_getblksz(size_t *sz, t_lnode *tree, t_lsnfo *info);
void				ls_putlink(char *path);
int					ls_listfile(t_lsnfo *info, char *name);
int					ls_listdir(t_lsnfo *info, char *dir);
#endif