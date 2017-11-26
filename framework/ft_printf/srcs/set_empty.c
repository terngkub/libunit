/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:33 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 21:38:24 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_empty(t_tag *tag, void **addr)
{
	if (tag && addr && tag->null_val && (tag->precision == 0))
	{
		if (tag->type >= O && tag->type <= ZO && tag->alter)
			return ;
		ft_memdel(addr);
		if (tag->width > 0)
		{
			*addr = (void *)ft_strnew(tag->width);
			*addr = ft_memset(*addr, (int)' ', tag->width);
		}
		else
			*addr = (void *)ft_strdup("");
	}
}
