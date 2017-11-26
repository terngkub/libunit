/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:41:53 by jdaufin           #+#    #+#             */
/*   Updated: 2017/04/21 12:13:18 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	jzx_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;
	char			*base;

	if ((tag->type == JX) || (tag->type == JXX))
	{
		base = (tag->type == JX ? HEXLO : HEXUP);
		input.jx = va_arg(*pap, uintmax_t);
		tag->null_val = input.jx == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.jx, base);
	}
	else if ((tag->type == ZX) || (tag->type == ZXX))
	{
		base = (tag->type == ZX ? HEXLO : HEXUP);
		input.zx = va_arg(*pap, size_t);
		tag->null_val = input.zx == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.zx, base);
	}
}

static void	hx_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;
	char			*base;

	if ((tag->type == HX) || (tag->type == HXX))
	{
		base = (tag->type == HX ? HEXLO : HEXUP);
		input.hx = (unsigned short int)va_arg(*pap, unsigned int);
		tag->null_val = input.hx == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.hx, base);
	}
	else if ((tag->type == HHX) || (tag->type == HHXX))
	{
		base = (tag->type == HHX ? HEXLO : HEXUP);
		input.hhx = (unsigned char)va_arg(*pap, unsigned int);
		tag->null_val = input.hhx == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.hhx, base);
	}
}

static void	lx_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;
	char			*base;

	if ((tag->type == LX) || (tag->type == LXX))
	{
		base = (tag->type == LX ? HEXLO : HEXUP);
		input.lx = va_arg(*pap, unsigned long int);
		tag->null_val = input.lx == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.lx, base);
	}
	else if ((tag->type == LLX) || (tag->type == LLXX))
	{
		base = (tag->type == LLX ? HEXLO : HEXUP);
		input.llx = va_arg(*pap, unsigned long long int);
		tag->null_val = input.llx == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.llx, base);
	}
}

void		x_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;
	char			*base;

	if (pap && tag && addr)
	{
		ft_memdel(addr);
		if ((tag->type == X) || (tag->type == XX))
		{
			base = (tag->type == X ? HEXLO : HEXUP);
			input.x = va_arg(*pap, unsigned int);
			tag->null_val = input.x == 0 ? 1 : 0;
			*addr = (void *)(tag->to_out.uitoa)(input.x, base);
		}
		else if ((tag->type == JX) || (tag->type == JXX) \
				|| (tag->type == ZX) || (tag->type == ZXX))
			jzx_to_str(pap, tag, addr);
		else if ((tag->type == HX) || (tag->type == HXX) \
				|| (tag->type == HHX) || (tag->type == HHXX))
			hx_to_str(pap, tag, addr);
		else if ((tag->type == LX) || (tag->type == LXX) \
				|| (tag->type == LLX) || (tag->type == LLXX))
			lx_to_str(pap, tag, addr);
	}
}
