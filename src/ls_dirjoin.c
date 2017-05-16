/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:09:17 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/15 14:50:44 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

char			*ls_dirjoin(const char *s1, const char *s2)
{
	char	*ns;
	int		i;
	int		it;

	i = 0;
	it = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ns = ft_strnew((ft_strlen(s1) + 1) + ft_strlen(s2))))
		return (NULL);
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i])
		{
			ns[i] = s1[i];
			i++;
		}
		if (ft_strcmp(s1, "/") != 0)
			ns[i++] = '/';
		while (s2[it])
			ns[i++] = s2[it++];
	}
	ns[i] = '\0';
	return (ns);
}
