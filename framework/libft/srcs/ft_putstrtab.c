/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:14:53 by jdaufin           #+#    #+#             */
/*   Updated: 2016/12/12 16:40:11 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The tab of charstrings sent must be terminated by a NULL pointer.
*/

#include "libft.h"

void	ft_putstrtab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		ft_putendl(tab[i++]);
}
