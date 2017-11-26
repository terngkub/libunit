/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:54:28 by jdaufin           #+#    #+#             */
/*   Updated: 2017/04/21 12:07:19 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	jzo_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == JO)
	{
		input.jo = va_arg(*pap, uintmax_t);
		tag->null_val = input.jo == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.jo, OCTAL);
	}
	else if (tag->type == ZO)
	{
		input.zo = va_arg(*pap, size_t);
		tag->null_val = input.zo == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.zo, OCTAL);
	}
}

static void	so_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == HO)
	{
		input.ho = (unsigned short int)va_arg(*pap, unsigned int);
		tag->null_val = input.ho == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.ho, OCTAL);
	}
	else if (tag->type == HHO)
	{
		input.hho = (unsigned char)va_arg(*pap, unsigned int);
		tag->null_val = input.hho == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.hho, OCTAL);
	}
}

static void	lo_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (tag->type == LO)
	{
		input.lo = va_arg(*pap, unsigned long int);
		tag->null_val = input.lo == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.lo, OCTAL);
	}
	else if (tag->type == LLO)
	{
		input.llo = va_arg(*pap, unsigned long long int);
		tag->null_val = input.llo == 0 ? 1 : 0;
		*addr = (void *)(tag->to_out.uitoa)(input.llo, OCTAL);
	}
}

void		o_to_str(va_list *pap, t_tag *tag, void **addr)
{
	union u_intype	input;

	if (pap && tag && addr)
	{
		ft_memdel(addr);
		if (tag->type == O)
		{
			input.o = va_arg(*pap, unsigned int);
			tag->null_val = input.o == 0 ? 1 : 0;
			*addr = (void *)(tag->to_out.uitoa)(input.o, OCTAL);
		}
		else if ((tag->type == JO) || (tag->type == ZO))
			jzo_to_str(pap, tag, addr);
		else if ((tag->type == HO) || (tag->type == HHO))
			so_to_str(pap, tag, addr);
		else if ((tag->type == LO) || (tag->type == LLO))
			lo_to_str(pap, tag, addr);
	}
}
