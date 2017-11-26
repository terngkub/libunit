/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_prefixes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:47:51 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 21:39:36 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	transfer_minus(char **ppad, void **addr)
{
	char	*swap;

	if (ppad && addr)
	{
		swap = ft_strdup((char *)(*addr + 1));
		ft_memdel(addr);
		*addr = swap;
		*ppad = ft_strjoin_free("-", 0, *ppad, 1);
	}
}

void	transfer_plus(char **ppad, void **addr)
{
	char	*swap;

	if (ppad && addr)
	{
		swap = ft_strdup((char *)(*addr + 1));
		ft_memdel(addr);
		*addr = swap;
		*ppad = ft_strjoin_free("+", 0, *ppad, 1);
	}
}

void	transfer_0x(char **ppad, void **addr)
{
	char	*swap;
	char	*pref_0x;

	if (!(ppad && addr))
		return ;
	pref_0x = ft_strsub((char *)*addr, 0, 2);
	swap = ft_strdup((char *)(*addr + 2));
	ft_memdel(addr);
	*addr = swap;
	*ppad = ft_strjoin_free(pref_0x, 1, *ppad, 1);
}
