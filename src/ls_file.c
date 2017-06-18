/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:31:45 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/16 16:32:03 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

char				*ls_getfile(char *argstr)
{
	char			*end;

	end = NULL;
	if (!(end = ft_strrchr(argstr, '/')))
		return (ft_strdup(argstr));
	else
		return (ft_strdup(end + 1));
}

char				*ls_getpath(char *argstr)
{
	char			*end;

	end = NULL;
	if (!(end = ft_strrchr(argstr, '/')))
		return (ft_strdup("./"));
	else
		return (ft_strndup(argstr, end - argstr));
}
