/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:44:06 by rlutt             #+#    #+#             */
/*   Updated: 2017/06/16 14:46:11 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

char			*ls_dirjoin(const char *stra, const char *strb)
{
	char		*ns;

	if (stra == NULL || strb == NULL)
		return (NULL);
	if (!(ns = ft_strnew((ft_strlen(stra) + 1) + ft_strlen(strb))))
		return (NULL);
	ft_strcpy(ns, (char *)stra);
	if (stra[ft_strlen(ns) - 1] != '/')
		ft_strcat(ns, "/");
	ft_strcat(ns, strb);
	return (ns);
}
