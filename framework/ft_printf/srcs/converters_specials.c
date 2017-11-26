/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_specials.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:04:34 by jdaufin           #+#    #+#             */
/*   Updated: 2017/05/23 20:01:26 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;
	char			*base;

	base = HEXLO;
	input.llx = (unsigned long long int)va_arg(*pap, void *);
	ft_memdel(addr);
	*addr = (void *)(tag->to_out.uitoa)(input.llx, base);
}

void	pc_to_str(t_tag *tag, void **addr)
{
	if (tag && addr && tag->type == PC)
	{
		ft_memdel(addr);
		*addr = ft_strdup("%");
	}
}
