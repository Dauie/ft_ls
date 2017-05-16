/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:09:17 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/15 22:23:58 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

char			*ls_dirjoin(const char *s1, const char *s2)
{
	char	*ns;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ns = ft_strnew((ft_strlen(s1) + 1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ns, (char *)s1);
	ft_strcat(ns, "/");
	ft_strcat(ns, s2);
	return (ns);
}
