/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:10:46 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/18 12:11:35 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

int			ls_isarg(int c)
{
	if (c == 'a')
		return (1);
	else if (c == 'A')
		return (2);
	else if (c == 'r')
		return (3);
	else if (c == 'R')
		return (4);
	else if (c == 'l')
		return (5);
	else if (c == 't')
		return (6);
	else
		return (0);
}
