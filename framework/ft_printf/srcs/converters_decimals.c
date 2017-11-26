/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_decimals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:29:24 by jdaufin           #+#    #+#             */
/*   Updated: 2017/06/09 15:21:33 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	jzd_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == JD)
	{
		input.jd = va_arg(*pap, intmax_t);
		tag->null_val = input.jd == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.itoa)(input.jd, DECIM);
	}
	else if (tag->type == ZD)
	{
		input.zd = (intmax_t)va_arg(*pap, size_t);
		tag->null_val = input.zd == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.itoa)(input.zd, DECIM);
	}
}

static void	sd_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == HD)
	{
		input.hd = (short int)va_arg(*pap, int);
		tag->null_val = input.hd == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.itoa)(input.hd, DECIM);
	}
	else if (tag->type == HHD)
	{
		input.hhd = (char)va_arg(*pap, int);
		tag->null_val = input.hhd == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.itoa)(input.hhd, DECIM);
	}
}

static void	ld_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == LD)
	{
		input.ld = va_arg(*pap, long int);
		tag->null_val = input.ld == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.itoa)(input.ld, DECIM);
	}
	else if (tag->type == LLD)
	{
		input.lld = va_arg(*pap, long int);
		tag->null_val = input.lld == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.itoa)(input.lld, DECIM);
	}
}

void		d_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (pap && tag && addr)
	{
		ft_memdel(addr);
		if (tag->type == D)
		{
			input.d = va_arg(*pap, int);
			tag->null_val = input.d == 0 ? 1 : 0;
			*addr = (void *)(tag->to_out.itoa)(input.d, DECIM);
		}
		else if ((tag->type == JD) || (tag->type == ZD))
			jzd_to_str(pap, tag, addr);
		else if ((tag->type == HD) || (tag->type == HHD))
			sd_to_str(pap, tag, addr);
		else if ((tag->type == LD) || (tag->type == LLD))
			ld_to_str(pap, tag, addr);
	}
}
