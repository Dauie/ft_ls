/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:10 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/05 18:43:09 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_ls_H
# define ft_ls_H

#include "../libft/incl/bool.h"
#include "../libft/incl/char.h"
#include "../libft/incl/cnvrsn.h"
#include "../libft/incl/gnl.h"
#include "../libft/incl/lst.h"
#include "../libft/incl/mem.h"
#include "../libft/incl/num.h"
#include "../libft/incl/put.h"
#include "../libft/incl/printf.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct		s_istat
{
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	time_t			atime;
	time_t			mtime;
	time_t			mntime;
}					t_istat;

typedef struct		s_node
{
	char			cdir[1024];
	char 			name[1024];
	struct stat		stat;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_trinode
{
	t_node	*elem;
	t_node	*ntmp;
	t_node	*ttmp;
}					t_trinode;

typedef struct		s_lsnfo
{
	char			**args;
	char			**dirs;
	size_t			dirc;
	char			type[12];
	char			cdir[1024];
	t_blean			l_flg;
	t_blean			A_flg;
	t_blean			a_flg;
	t_blean			R_flg;
	t_blean			r_flg;
	t_blean			t_flg;
}					t_lsnfo;

int					ls_start(t_lsnfo *db);
int					ls_reg(t_lsnfo *db);
int					ls_chkdirnam(t_lsnfo *db, char *dirnam);
int					ls_anaargs(t_lsnfo *db);
int					ls_vrfydir(t_lsnfo *db, char *argstr);
void				manage_lsattrib(t_lsnfo *db);
void				ls_addtnoden(t_node **tree, char *name);
void				ls_addtnodet(t_node **tree, char *name);
void				ls_cleartree(t_node **tree);
void				ls_initdb(t_lsnfo *db);
void				ls_initnode(t_node *node);
int					ls_isarg(int c);
int			 		ls_tickargs(t_lsnfo *db, char *argstr);
void				ls_printtree(t_node *tree);
void				ls_revprinttree(t_node *tree);
int					ls_treesearch(t_node *tree, char *name);
unsigned int		ls_diramnt(t_node *tree);
void				ls_dirtotbl(t_node *tree, t_lsnfo *db, char **av, size_t inx);
int					main(int ac, char **av);
int					ls_preprecurs(t_lsnfo *db);


# endif
