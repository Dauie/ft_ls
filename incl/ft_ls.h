/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:10 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/11 09:51:31 by rlutt            ###   ########.fr       */
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
#include <time.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

# define MXNAMLEN 1024
# define MXTYPLEN 42

typedef struct		s_rnode
{
	char			name[MXNAMLEN];
	struct s_rnode	*left;
	struct s_rnode	*right;
}					t_rnode;

typedef struct		s_trirnode
{
	t_rnode			*elem;
	t_rnode			*ntmp;
	t_rnode			*ttmp;
}					t_trirnode;

typedef struct		s_node
{
	char			cdir[MXNAMLEN];
	char 			name[MXNAMLEN];
	struct stat		stat;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

typedef struct		s_trinode
{
	t_node			*elem;
	t_node			*ntmp;
	t_node			*ttmp;
}					t_trinode;

typedef struct		s_lsnfo
{
	char			**args;
	char			**dirs;
	size_t			dirc;
	char			type[MXTYPLEN];
	char			cdir[MXNAMLEN];
	t_blean			l_flg;
	t_blean			A_flg;
	t_blean			a_flg;
	t_blean			R_flg;
	t_blean			r_flg;
	t_blean			t_flg;
}					t_lsnfo;

int					ls_start(t_lsnfo *db);
int					ls_reg(t_lsnfo *db);
void				ls_putmeta(t_node *node, t_lsnfo *info);
int					ls_chkdirnam(t_lsnfo *db, char *dirnam);
int					ls_anaargs(t_lsnfo *db);
int					ls_vrfydir(t_lsnfo *db, char *argstr);
void				manage_lsattrib(t_lsnfo *db);
void				ls_addtnoden(t_node **tree, char *name);
void				ls_addtnodet(t_node **tree, char *name);
void				ls_addrnoden(t_rnode **tree, char *name);
void				ls_cleartree(t_node **tree);
void				ls_clearrtree(t_rnode **tree);
void				ls_initdb(t_lsnfo *db);
void				ls_initnode(t_node *node);
void				ls_initrnode(t_rnode *node);
int					ls_isarg(int c);
int			 		ls_tickargs(t_lsnfo *db, char *argstr);
void				ls_printtree(t_node *tree);
void				ls_printtreel(t_node *tree, t_lsnfo *info);
void				ls_revprinttree(t_node *tree);
int					ls_treesearch(t_node *tree, char *name);
unsigned int		ls_diramnt(t_node *tree);
char				*ls_dirjoin(char const *s1, char const *s2);
void				ls_dirtotbl(t_node *tree, t_lsnfo *db, char **av, size_t inx);
int					main(int ac, char **av);
int					ls_preprecurs(t_lsnfo *db);
void				ls_revprinttreel(t_node *tree, t_lsnfo *info);



# endif
